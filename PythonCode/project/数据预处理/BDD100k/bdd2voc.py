# -*- coding: utf8 -*-
import os,time

from scipy.fft import dst
import pascal_voc_io
import parseJson

def main(srcDir, dstDir):
    i = 1
    # os.walk()
    # dirName是你所要遍历的目录的地址, 返回的是一个三元组(root,dirs,files)
    # root所指的是当前正在遍历的这个文件夹的本身的地址
    # dirs是一个 list ，内容是该文件夹中所有的目录的名字(不包括子目录)
    # files 同样是 list , 内容是该文件夹中所有的文件(不包括子目录)
    cnt = 0
    for dirpath, dirnames, filenames in os.walk(srcDir):
#        print(dirpath, dirnames, filenames)
        for filepath in filenames:
            fileName = os.path.join(dirpath,filepath)
            #print(fileName)
            print("processing: {}, {}".format(i, fileName))
            i = i + 1
            xmlFileName = filepath[:-5] # remove ".json" 5 character
            # 解析该json文件，返回一个列表的列表，存储了一个json文件里面的所有方框坐标及其所属的类
            objs = parseJson.parseJson(str(fileName)) 
            # 如果存在检测对象，创建一个与该json文件具有相同名的VOC格式的xml文件
            if len(objs):
                tmp = pascal_voc_io.PascalVocWriter(dstDir, xmlFileName, (720,1280,3), fileName)
                for obj in objs:
                    tmp.addBndBox(obj[0],obj[1],obj[2],obj[3],obj[4])
                tmp.save()
            else:
                cnt += 1
                print(f'-----Blank picture count:{cnt};Name:{fileName}-----')
                with open('./bdd_blank_pic.txt', 'a+') as f:
                    f.writelines(f"{fileName}\n")
    
    print(f"Blank picture count: {cnt}")

if __name__ == '__main__':
    # test
    # these paths should be your own path
    srcDir = '/Users/lucifer/Downloads/DataSet/BDD100K/bdd100k_label/labels/100k/val'
    dstDir = '/Users/lucifer/Downloads/DataSet/BDD100K/bdd100k_label/Annotations/val_filter_small_truncated_occ'

    if(not os.path.exists(dstDir)):
        print("Destination Dir Not Found！Create New Directory！")
        time.sleep(1)
        os.mkdir(dstDir)

    # srcDir = '/Users/lucifer/Downloads/DataSet/BDD100K/bdd100k_label/labels/100k/train'
    # dstDir = '/Users/lucifer/Downloads/DataSet/BDD100K/bdd100k_label/Annotations/train_new'
    main(srcDir, dstDir)
