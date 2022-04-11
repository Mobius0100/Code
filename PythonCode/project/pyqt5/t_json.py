import json

test_dic = {"center_ip":"192.168.2.1", "box_ip":"192.168.2.2", "video_ip": "192.168.0.123", "time": "2022-01-02 12:00:00", "event_type": "helmet", "description": "2022-01-02 12:00:00, 工地后门，检测到有2人未戴安全帽", "file_type": 0, "file_name": "demo2.jpg"
}

def main():
    # store(test_dic)
    openjson()

def store(test_dic):
    with open("/Users/lucifer/PythonCode/log.json", "a") as f:
        json_str = json.dump(test_dic, f, ensure_ascii=False, indent=4, separators=(', ', ': '))
        print("successful")

def openjson():
    with open("/Users/lucifer/PythonCode/log.json", 'r') as f:
        temp = json.load(f)
        print(type(temp))
        print(len(temp))
        for i in temp:
            print(temp[i]['description'])

main()