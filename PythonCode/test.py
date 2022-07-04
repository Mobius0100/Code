import json
import os

categorys = ['car', 'bus', 'person', 'truck']

def parseJson(jsonfile):
    objs = []
    obj = []
    cnt = 0
    f = open(jsonfile)
    info = json.load(f)
    objects = info['frames'][0]['objects']

    for i in objects:
        flag = i['attributes']['truncated']
        print(flag)
        print(cnt)
    
    for root, dirs, files in os.walk("/Users/lucifer/Code/PythonCode/project"):
        print(f"root:{root}; dirs:{dirs}; files:{files}\n")

parseJson('/Users/lucifer/Code/PythonCode/test.json')