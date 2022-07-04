import os
import xml.etree.ElementTree as ET

root_dir = '/Users/lucifer/Downloads/DataSet/未命名文件夹'
out_dir = '/Users/lucifer/Downloads/DataSet/未命名文件夹2'

def bboxes2xml(folder, img_name, width, height, gts, xml_save_to):
    xml_file = open((xml_save_to + '/' + img_name + '_' + img_name[:9]  + '.xml'), 'w')
    xml_file.write('<annotation>\n')
    xml_file.write('    <folder>' + folder + '</folder>\n')
    xml_file.write('    <filename>' + str(img_name) + '.jpg' + '</filename>\n')
    xml_file.write('    <size>\n')
    xml_file.write('        <width>' + str(width) + '</width>\n')
    xml_file.write('        <height>' + str(height) + '</height>\n')
    xml_file.write('        <depth>3</depth>\n')
    xml_file.write('    </size>\n')

    for gt in gts:
        xml_file.write('    <object>\n')
        xml_file.write('        <name>' + str(gt[0]) + '</name>\n')
        xml_file.write('        <pose>Unspecified</pose>\n')
        xml_file.write('        <truncated>0</truncated>\n')
        xml_file.write('        <difficult>0</difficult>\n')
        xml_file.write('        <bndbox>\n')
        xml_file.write('            <xmin>' + str(gt[1]) + '</xmin>\n')
        xml_file.write('            <ymin>' + str(gt[2]) + '</ymin>\n')
        xml_file.write('            <xmax>' + str(gt[3]) + '</xmax>\n')
        xml_file.write('            <ymax>' + str(gt[4]) + '</ymax>\n')
        xml_file.write('        </bndbox>\n')
        xml_file.write('    </object>\n')

    xml_file.write('</annotation>')
    xml_file.close()

for xml_file in os.listdir(root_dir):
    xml_path = os.path.join(root_dir, xml_file)

    tree = ET.parse(xml_path)
    root = tree.getroot()
    all_frames = root.findall("frame")
    file_name = root.attrib["name"]

    if not os.path.exists(os.path.join(out_dir, file_name)):
        os.makedirs(os.path.join(out_dir, file_name))

    for frame in all_frames:
        attrib = frame.attrib["num"]
        zfill = attrib.zfill(5)
        img_name = "img" + zfill

        print(f'--------------------------{img_name}....')

        info = []
        target_list = frame.findall("target_list")[0]

        all_targets = target_list.findall("target")
        for target in all_targets:
            info_tmp = []
            lable_name = target.findall("attribute")[0].attrib["vehicle_type"]
            info_tmp.append(lable_name)
            
            box_dict = target.findall("box")[0].attrib

            xmin = float(box_dict["left"])
            ymin = float(box_dict["top"])
            width = float(box_dict["width"])
            height = float(box_dict["height"])
            xmax=xmin+width
            ymax=ymin+height

            info_tmp.append(int(xmin))
            info_tmp.append(int(ymin))
            info_tmp.append(int(xmax))
            info_tmp.append(int(ymax))

            info.append(info_tmp)

        folder = "images"
        width = 960
        height = 540
        xml_save_to = out_dir
        img_names = file_name + '/' + img_name

        bboxes2xml(folder, img_names, width, height, info, xml_save_to)
        print("done")

        print("----------------------------------------")