from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn import tree
from sklearn.tree import plot_tree
import matplotlib.pyplot as plt

# 获取葡萄酒据集，sklearn库提供
wines = datasets.load_wine()
"""
共178个样本，样本具有13个特征值(feature_names)
feature_names:
    alcohol: 酒精
    malic_acid: 苹果酸
    ash: 灰
    alcalinity_of_ash: 灰的碱性
    magnesium: 镁
    total_phenols: 总酚
    flavanoids: 类黄酮
    nonflavanoid_phenols: 非黄烷类酚类
    proanthocyanins: 花青素
    color_intensity: 颜色强度
    hue: 色调
    od280/od315_of_diluted_wines: od280/od315稀释葡萄酒
    proline: 脯氨酸
三种红酒类型(classes)
classes:
    class_0
    class_1
    class_2
"""
print("葡萄酒类型", list(wines.target_names))  # ['class_0', 'class_1', 'class_2']
print("样本特征值", list(wines.feature_names))  # 太长，见注释
print("数据规模", wines.data.shape)  # (178, 13)

x_train, x_test, y_train, y_test = train_test_split(wines.data, wines.target, test_size=0.3)  # 分训练集、测试集  测试集占0.3
print("训练集", x_train.shape)
print("测试集", x_test.shape)

clf = tree.DecisionTreeClassifier()  # 载入决策树分类模型
clf = clf.fit(x_train, y_train)
score = clf.score(x_test, y_test)
print("准确度", score)

plt.rcParams['font.sans-serif']=['Arial Unicode MS'] #用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False #用来正常显示负号
feature_name = ['酒精', '苹果酸', '灰', '灰的碱性', '镁', '总酚', '类黄酮', '非黄烷类酚类', '花青素', '颜色强度', '色调', 'od280/od315稀释葡萄酒', '脯氨酸']
class_names = ["一级", "二级", "三级"]
plt.figure(figsize=(12,8))
plot_tree(clf,
    feature_names = feature_name,
    class_names=class_names,
    filled=True)
plt.show()