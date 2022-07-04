#!/usr/bin/env python
# -*- coding: utf8 -*-
#parse json，input json filename,output info needed by voc

import json
#这里是我需要的10个类别
categorys = ['car', 'bus', 'person', 'truck']

def parseJson(jsonFile):
    '''
      params:
        jsonFile -- BDD00K数据集的一个json标签文件
      return:
        返回一个列表的列表，存储了一个json文件里面的方框坐标及其所属的类，
        形如：[[325, 342, 376, 384, 'car'], [245, 333, 336, 389, 'car']]
    '''
    objs = []
    obj = []
    f = open(jsonFile)
    info = json.load(f)
    objects = info['frames'][0]['objects']
    for i in objects:

      if(i['category'] in categorys):
        # 过滤截断、遮挡目标
        #flag = (i['attributes']['truncated'] or i['attributes']['occluded'])
        flag = (i['attributes']['truncated'])
        obj.append(int(i['box2d']['x1']))
        obj.append(int(i['box2d']['y1']))
        obj.append(int(i['box2d']['x2']))
        obj.append(int(i['box2d']['y2']))
        obj.append(i['category'])
        
        # 过滤小目标,目标大小大于32x32
        area = abs(obj[2] - obj[0]) * abs(obj[3] - obj[1])
        if(area >= 1024 and (not flag)):
          objs.append(obj)
        obj = []

    return objs
