'''
    从每个图片文件夹中抽取图片，存入同一文件夹中
    cnt：每隔多少图片抽一张
'''

import os
import shutil
from pathlib import Path


from torch import rand

FILE_ROOT = Path(r"/Users/lucifer/Downloads/DataSet/BDD100K")

ORI_IMG_DIR = FILE_ROOT.joinpath('bdd100k_img', 'train')
ORI_LABEL_DIR = FILE_ROOT.joinpath('bdd100k_label', 'Annotations', 'train')

OUT_IMG_DIR = FILE_ROOT.joinpath('Images')
OUT_LABEL_DIR = FILE_ROOT.joinpath('Labels')

def mkdirs(d):
    if not os.path.exists(d):
        os.makedirs(d)

mkdirs(OUT_LABEL_DIR)
mkdirs(OUT_IMG_DIR)

cnt = 5
copy_file_path = []

img_list = [s for s in os.listdir(ORI_LABEL_DIR)]

for copy_file in img_list[::cnt]:
    copy_file = copy_file[:-4]
    img_file = ORI_IMG_DIR.joinpath(copy_file).with_suffix('.jpg')
    lable_file = ORI_LABEL_DIR.joinpath(copy_file).with_suffix('.xml')

    copy_file_path.append(copy_file)
    dict_img_file = OUT_IMG_DIR.joinpath(copy_file).with_suffix('.jpg')
    dict_label_file = OUT_LABEL_DIR.joinpath(copy_file).with_suffix('.xml')

    shutil.copyfile(img_file, dict_img_file)
    shutil.copyfile(lable_file, dict_label_file)
 
    print(f'{copy_file} ----->Done!')
    # shutil.copy(ori_file, dict_file)
        
print(len(copy_file_path))

