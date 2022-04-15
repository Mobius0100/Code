import numpy as np
import pandas as pd
from sklearn.tree import DecisionTreeClassifier, plot_tree
import matplotlib.pyplot as plt
from sklearn import metrics
from sklearn.model_selection import train_test_split, KFold
import seaborn as sns

#
tag = ['买入价', '维护费', '车门数', '可容纳人数', '后备箱大小', '安全性', '评测']
plt.rcParams['font.sans-serif']=['Arial Unicode MS'] #用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False #用来正常显示负号
# pd输出中文对齐设置
pd.set_option('display.unicode.ambiguous_as_wide', True)
pd.set_option('display.unicode.east_asian_width', True)

#决策树模型
tree_clf = DecisionTreeClassifier(criterion="entropy", max_depth=10)

#数据导入
raw_data = pd.read_table('car_1000.txt', header=None, sep=',')    # txt使用table,csv使用csv
raw_data.columns = tag
train_data = raw_data.copy()


def data_show(data):
    # print(df.iloc[:, 0].value_counts()) # iloc[:, cnt]表示选取列
    #查看数据特征
    print('数据大小：')
    print(data.info(), '\n************************')
    print('数据简介：\n', data.head(), '\n************************')
    print('数据标签：', data.columns, '\n************************')
    print('数据特征：\n************************')
    for i in data.columns:
        print(data[i].value_counts())
        print('************************')
    
    print('数据类别：\n',data.iloc[:,-1].unique())
    print('************************')
    print('数据描述：\n', data.describe())
    print('************************')

def pre_data():
    #数值化映射
    rank_map = {'low':1, 'med':2, 'high':3, 'vhigh':4}
    size_map = {'small':1, 'med':2, 'big':3}

    # train['Title'].fillna(0, inplace=True) # 空值处理
    train_data['买入价'] = train_data['买入价'].map(rank_map).astype(float)
    train_data['安全性'] = train_data['安全性'].map(rank_map).astype(float)
    train_data['维护费'] = train_data['维护费'].map(rank_map).astype(float)
    train_data['后备箱大小'] = train_data['后备箱大小'].map(size_map).astype(float)
    train_data['可容纳人数'] = train_data['可容纳人数'].replace('more', 5).astype(float)
    train_data['车门数'] = train_data['车门数'].replace('5more', 5).astype(float)

def show_metri(x_train, x_test, y_train, y_test):
    train_pred = tree_clf.predict(x_train)
    test_pred = tree_clf.predict(x_test)
    print('The accuracy of the Logistic Regression is:',metrics.accuracy_score(y_train,train_pred))
    print('The accuracy of the Logistic Regression is:',metrics.accuracy_score(y_test,test_pred))
    # print(test_pred)
    # print(y_test)
    confusion_matrix_result = metrics.confusion_matrix(test_pred,y_test)
    print('The confusion matrix result:\n',confusion_matrix_result) 

    plt.figure(figsize=(8, 6))
    sns.heatmap(confusion_matrix_result, annot=True, cmap='Blues')
    plt.xlabel('Predicted labels')
    plt.ylabel('True labels')
    plt.show()

def k_cross_alidation(depth=10):
    # tree_clf = DecisionTreeClassifier(criterion="entropy", max_depth=depth)
    data = train_data.iloc[:,0:6]
    target = train_data.iloc[:, 6]
    accuracy = []
    '''
        KFold的使用方法
    '''
    kf = KFold(n_splits=10, shuffle=True, random_state=44) # shuffle表示是否打乱数据集,random_state表示随机种子
    for train_index, test_index in kf.split(data):         
        x_train, x_test = data.loc[train_index].to_numpy(), data.loc[test_index].to_numpy()
        y_train, y_test = target.loc[train_index].to_numpy(), target.loc[test_index].to_numpy()
        tree_clf.fit(x_train, y_train)
        acc = tree_clf.score(x_test, y_test)
        accuracy.append(acc)
        show_metri(x_train, x_test, y_train, y_test)
    
    print(accuracy)
    print('精度：', np.average(accuracy))
    # show()

def show():
    fn=tag[0:6]
    cn=['unacc', 'acc', 'good', 'vgood']

    plt.figure(figsize=(22,8))
    plot_tree(tree_clf,
            feature_names = fn,
            class_names=cn,
            filled=True)
    plt.savefig('./DTree.pdf',dpi=400)
    plt.show()

def main():
    pre_data()
    # data_show(train_data)
    # data_show(raw_data)
    # for i in range(1,20):
    #     print(f"*************深度：{i}************\n")
    k_cross_alidation()
    

main()