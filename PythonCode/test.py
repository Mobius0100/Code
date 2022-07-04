import json

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

parseJson('/Users/lucifer/Code/PythonCode/test.json')