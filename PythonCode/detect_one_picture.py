import argparse
import io
import torch.backends.cudnn as cudnn

from models.experimental import *
from utils.datasets import *
from utils.utils import *
from utils.create_xml import *


def load_model():
    weights = opt.weights
    device = torch_utils.select_device(opt.device)
    model = attempt_load(weights, map_location=device)  # load FP32 model
    half = device.type != 'cpu'  # half precision only supported on CUDA
    if half:
        model.half()  # to FP16
    print('%s'%('-') * 80)
    return model,device,half

def detect(img0):
    weights, view_img, save_txt, imgsz = opt.weights, opt.view_img, opt.save_txt, opt.img_size
    t0 = time.time()
    # if request.method == 'POST':
    #     print(request)
    #     if not request.files.get('file'):
    #         return {"error":"未正常传图片"}
    #     print(request.files["file"])
    #     img = request.files["file"].read()
    #     # print(img0)
    #     # img0 = Image.open(io.BytesIO(img0))
    #     img0 = cv2.imdecode(np.frombuffer(img, np.uint8), cv2.IMREAD_COLOR)
    #     # cv2.imwrite('img0.jpg',img0)
    #     print('成功读取图片')
    # else:
    #     return {"error":'请求错误'}


    imgsz = check_img_size(imgsz, s=model.stride.max())  # check img_size

    # Get names and colors
    names = model.module.names if hasattr(model, 'module') else model.names
    # colors = [[random.randint(0, 255) for _ in range(3)] for _ in range(len(names))]
    colors = [[255,0,0],[0,255,0],[0,0,255],[0,255,0],[0,0,255]]
    # print(colors)
    # Run inference
    # t0 = time.time()
    img = torch.zeros((1, 3, imgsz, imgsz), device=device)  # init img
    _ = model(img.half() if half else img) if device.type != 'cpu' else None  # run once

    img = letterbox(img0, new_shape=imgsz)[0]

    # Convert
    img = img[:, :, ::-1].transpose(2, 0, 1)  # BGR to RGB, to 3x416x416
    img = np.ascontiguousarray(img)

    # predict
    image = torch.from_numpy(img).to(device)
    image = image.half() if half else image.float()  # uint8 to fp16/32
    image /= 255.0  # 0 - 255 to 0.0 - 1.0
    if image.ndimension() == 3:
        image = image.unsqueeze(0)

    # Inference

    pred = model(image, augment=opt.augment)[0]

    # Apply NMS
    pred = non_max_suppression(pred, opt.conf_thres, opt.iou_thres, classes=opt.classes, agnostic=opt.agnostic_nms)
    # t2 = torch_utils.time_synchronized()

    data = {"head":[], "cloth":[]}
    head_is_not, cloth_is_not = False, False
    # print(pred)
    # Process detections
    for i, det in enumerate(pred):  # detections per image

        if det is not None and len(det):
            # Rescale boxes from img_size to im0 size
            det[:, :4] = scale_coords(image.shape[2:], det[:, :4], img0.shape).round()
            persons = [[int(xyxy[0]), int(xyxy[1]), int(xyxy[2]), int(xyxy[3])] for *xyxy,conf,cls in det if cls==0]
            print(persons)
            for *xyxy, conf, cls in det:
                if cls == 0:
                    continue
                x0y0x1y1 = [int(xyxy[0]), int(xyxy[1]), int(xyxy[2]), int(xyxy[3])]
                in_person = False
                for person in persons:
                    if contain(person,x0y0x1y1):
                        in_person = True
                        break
                if not in_person:
                    continue
                if names[int(cls)] == 'head':
                    head_is_not = True
                    data["head"].append(x0y0x1y1)
                if names[int(cls)] == 'cloth':
                    cloth_is_not = True
                    data["cloth"].append(x0y0x1y1)
                label = '%s %.2f' % (names[int(cls)], conf)
                plot_one_box(xyxy, img0, label=label, color=colors[int(cls)], line_thickness=2)
            cv2.imwrite('img0.jpg',img0)
    # print(pred)
    if head_is_not:
        message = '有人没戴安全帽'
        if cloth_is_not:
            message += ',有人没穿反光衣'
    elif cloth_is_not:
        message = '有人没穿反光衣'
    else:
        message = '正常'
    print(message)
    return img0

def contain(rect1, rect2):
    xmin1, ymin1, xmax1, ymax1 = rect1
    xmin2, ymin2, xmax2, ymax2 = rect2
    # s1 = (xmax1 - xmin1) * (ymax1 - ymin1)
    s2 = (xmax2 - xmin2) * (ymax2 - ymin2)


    left = max(xmin2, xmin1)
    right = min(xmax2, xmax1)
    top = max(ymin2, ymin1)
    bottom = min(ymax2, ymax1)

    if left >= right or top >= bottom:
        return False

    intersection = (right - left) * (bottom - top)
    if intersection / s2 > 0.5:
        return True
    else:
        return False


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--weights', nargs='+', type=str, default='./runs/best.pt', help='model.pt path(s)')
    parser.add_argument('--source', type=str, default=f'inference/images', help='source')  # file/folder, 0 for webcam
    parser.add_argument('--output', type=str, default='inference/output', help='output folder')  # output folder
    parser.add_argument('--xml', type=str, default='inference/xml', help='output xml folder')  # output folder
    parser.add_argument('--img-size', type=int, default=640, help='inference size (pixels)')
    parser.add_argument('--conf-thres', type=float, default=0.5, help='object confidence threshold')
    parser.add_argument('--iou-thres', type=float, default=0.4, help='IOU threshold for NMS')
    parser.add_argument('--device', default='', help='cuda device, i.e. 0 or 0,1,2,3 or cpu')
    parser.add_argument('--view-img', action='store_true', help='display results')
    parser.add_argument('--save-txt', action='store_true', help='save results to *.txt')
    parser.add_argument('--classes', nargs='+', type=int, help='filter by class: --class 0, or --class 0 2 3')
    parser.add_argument('--agnostic-nms', action='store_true', help='class-agnostic NMS')
    parser.add_argument('--augment', action='store_true', help='augmented inference')
    parser.add_argument('--update', action='store_true', help='update all models')
    opt = parser.parse_args()
    print(opt)
    model, device, half = load_model()

    vidcap = cv2.VideoCapture(0)
    #vidcap1 = cv2.VideoCapture(1)
    vidcap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
    vidcap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
    ret, frame = vidcap.read()
    #net1, frame1 = vidcap1.read()    
    
    cv2.namedWindow("detect", 0)
    #cv2.resizeWindow("detect", 1280, 720)
    count = 1
    while ret:
        ret, frame = vidcap.read()
        frame = detect(frame)
        cv2.imshow("detect", frame)
        cv2.waitKey(1)
        count += 1
    # cv2.destroyAllWindows()
    vidcap.release()




