## 使用脚本将BDD数据集的json标注转换为yolo或者voc格式
### 一、使用步骤
1. bdd2voc.py 生成voc的xml文件
2. 对parseJson.py 进行修改，过滤相关标签
3. gen_head.py 将xml文件转成yolo的txt文件