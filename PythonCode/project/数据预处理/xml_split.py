import xml.etree.ElementTree as ET
import os

ori_dir = '/Users/lucifer/Downloads/DataSet/UA-DETRAC(车辆检测数据集8250车辆)(1)/DETRAC-Test-Annotations-XML'
out_dir = '/Users/lucifer/Downloads/DataSet/UA-DETRAC(车辆检测数据集8250车辆)(1)/Split_xml'

for i in os.listdir(ori_dir):
    tree = ET.parse(os.path.join(ori_dir, i))
    

