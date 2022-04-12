import numpy as np
import pandas as pd
from sklearn.tree import DecisionTreeClassifier
import matplotlib.pyplot as plt
from sklearn.tree import plot_tree
from sklearn.model_selection import train_test_split, KFold

#
tag = ['买入价', '维护费', '车门数', '可容纳人数', '后备箱大小', '安全性', '评测']
plt.rcParams['font.sans-serif']=['Arial Unicode MS'] #用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False #用来正常显示负号

#决策树模型
tree_clf = DecisionTreeClassifier(criterion="entropy")

#数据导入
df = pd.read_table('car_1000.txt', header=None, sep=',')    # txt使用table,csv使用csv
df.columns = tag
data = df.iloc[:,0:6]
target = df.iloc[:, 6]
# print(tag[0:6])

def k_cross_alidation():
    accuracy = []
    kf = KFold(n_splits=10, shuffle=True) # shuffle表示是否打乱数据集,random_statae表示随机种子
    for train_index, test_index in kf.split(data): 
        x_train, x_test = data.loc[train_index].to_numpy(), data.loc[test_index].to_numpy()
        y_train, y_test = target.loc[train_index].to_numpy(), target.loc[test_index].to_numpy()
        tree_clf.fit(x_train, y_train)
        acc = tree_clf.score(x_test, y_test)
        accuracy.append(acc)
    
    print(accuracy)
    print('精度：', np.average(accuracy))
    show()

def show():
    fn=tag[0:6]
    cn=['unacc', 'acc', 'good', 'vgood']

    plt.figure(figsize=(12,8))
    plot_tree(tree_clf,
            feature_names = fn,
            class_names=cn,
            filled=True)
    plt.show()

def main():
    k_cross_alidation()

main()