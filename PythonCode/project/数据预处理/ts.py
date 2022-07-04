from pathlib import Path
import shutil
l = []
root_path = Path('/Users/lucifer/Downloads/DataSet/UA-DETRAC(车辆检测数据集8250车辆)(1)')
dis_path = Path('/Users/lucifer/Downloads/DataSet/UA-DETRAC(车辆检测数据集8250车辆)(1)/VOC/test_xml')
with open('/Users/lucifer/Downloads/DataSet/UA-DETRAC(车辆检测数据集8250车辆)(1)/VOC/data_split/test.txt', 'r') as f:
    l = f.read().splitlines()

for i in l:
    file_path = root_path.joinpath('all_xml', i[-9:], i).with_suffix('.xml')
    out_path = dis_path.joinpath(i).with_suffix('.xml')
    shutil.copyfile(file_path, out_path)
