import numpy as np
import pandas as pd
from sklearn import tree
from sklearn.tree import DecisionTreeClassifier, plot_tree
import matplotlib.pyplot as plt
from sklearn import metrics
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split, KFold, cross_val_score
import seaborn as sns

tag = ['买入价', '维护费', '车门数', '可容纳人数', '后备箱大小', '安全性', '评测']
plt.rcParams['font.sans-serif']=['Arial Unicode MS'] #用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False #用来正常显示负号
# pd输出中文对齐设置
pd.set_option('display.unicode.ambiguous_as_wide', True)
pd.set_option('display.unicode.east_asian_width', True)

#决策树模型
# max_depth用于预剪枝，控制树的深度
# criterion划分方法，gini==CRAT，entropy==ID3
tree_clf = DecisionTreeClassifier(criterion="entropy", ccp_alpha=0, max_depth=5)

#数据导入
raw_data = pd.read_table('car_1000.txt', header=None, sep=',')    # txt使用table,csv使用csv
raw_data.columns = tag
train_data = raw_data.copy()


def data_show(data):
    '''
    查看数据特征
    '''
    # print(df.iloc[:, 0].value_counts()) # iloc[:, cnt]表示选取列
    
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

def label_encode():
    '''
    ## sklearn的标签编码方法处理数值映射
    '''
    
    train_data = pd.DataFrame()
    label = LabelEncoder()
    for c in raw_data.columns[:-1]:
        if raw_data[c].dtype == 'object':
            train_data[c] = label.fit_transform(raw_data[c])
        else:
            train_data[c] = raw_data[c]
    
    return train_data

def pre_data():
    '''
    ## 对数据进行数值化映射
    '''
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
    '''
        ## 显示数据集训练的混淆矩阵
    '''
    labels = ['acc', 'good','unacc','vgood']
    train_pred = tree_clf.predict(x_train)
    test_pred = tree_clf.predict(x_test)
    print('The accuracy of the Logistic Regression is:',metrics.accuracy_score(y_train,train_pred))
    print('The accuracy of the Logistic Regression is:',metrics.accuracy_score(y_test,test_pred))
    # print(test_pred)
    # print(y_test)
    confusion_matrix_result_test = metrics.confusion_matrix(test_pred,y_test)
    print('The confusion matrix result:\n',confusion_matrix_result_test) 

    confusion_matrix_result_train = metrics.confusion_matrix(train_pred,y_train)
    print('The confusion matrix result:\n',confusion_matrix_result_train) 

    plt.figure(figsize=(16, 6))
    plt.subplot(121)
    sns.heatmap(confusion_matrix_result_train, annot=True, fmt='.20g', cmap='Blues', xticklabels=labels, yticklabels=labels)
    plt.title('Train Matrix')
    plt.xlabel('Predicted labels')
    plt.ylabel('True labels')

    plt.subplot(122)
    sns.heatmap(confusion_matrix_result_test, annot=True, fmt='.20g', cmap='Greens', xticklabels=labels, yticklabels=labels)
    plt.title('Test Matrix')
    plt.xlabel('Predicted labels')
    plt.ylabel('True labels')
    plt.show()

def k_cross_validation(depth=10 , k_splits = 10):
    data = train_data.iloc[:, 0:6]
    target = train_data.iloc[:, 6]

    test_accuracy = []
    train_accuracy = []
    # print(data, target)
    '''
        KFold的使用方法
    '''
    kf = KFold(n_splits=k_splits, shuffle=True, random_state=11) # shuffle表示是否打乱数据集,random_state表示随机种子

    clfs = []
    for train_index, test_index in kf.split(data):     
        # tree_clf = DecisionTreeClassifier(criterion="entropy", random_state=11)    
        x_train, x_test = data.loc[train_index].to_numpy(), data.loc[test_index].to_numpy()
        y_train, y_test = target.loc[train_index].to_numpy(), target.loc[test_index].to_numpy()
        #训练决策树
        tree_clf.fit(x_train, y_train) 
        #计算准确率
        test_accuracy.append(tree_clf.score(x_test, y_test))
        train_accuracy.append(tree_clf.score(x_train, y_train))

        # clfs.append(tree_clf)
        # show_metri(x_train, x_test, y_train, y_test)
    # 同上，kfold的使用方法
    print("k折交叉验证结果：")
    print(cross_val_score(tree_clf, cv=kf, X=data, y=target)) 

    print(f'测试集平均准确度：{np.average(test_accuracy)}')
    print(f'训练集平均准确度：{np.average(train_accuracy)}')
    # train_scores = [clf.score(x_train, y_train) for clf in clfs]
    # test_scores = [clf.score(x_test, y_test) for clf in clfs]

    fig, ax = plt.subplots()
    ax.set_xlabel("cnt")
    ax.set_ylabel("accuracy")
    ax.set_title("Accuracy for training and testing sets")
    ax.plot(train_accuracy, marker="o", label="train")
    ax.plot(test_accuracy, marker="o", label="test")
    ax.legend()
    plt.show()


def show():
    '''
        显示决策树
    '''
    fn=tag[0:6]
    cn=['unacc', 'acc', 'good', 'vgood']

    plt.figure(figsize=(22,8))
    plot_tree(tree_clf,
            feature_names = fn,
            class_names=cn,
            filled=True)
    plt.savefig('./DTree.pdf',dpi=400)
    plt.show()

def hold_out(rate):
    '''
        留出法
    '''
    data = train_data.iloc[:,0:6]
    target = train_data.iloc[:, 6]
    x_train, x_test, y_train, y_test = train_test_split(data, target, test_size=rate, random_state=11, shuffle=True)
    tree_clf.fit(x_train, y_train)
    print(f'测试集比例{rate}，留出法准确度：{tree_clf.score(x_test, y_test)}')
    print(f'测试集比例{rate}，留出法训练准确度：{tree_clf.score(x_train, y_train)}')
    show_metri(x_train, x_test, y_train, y_test)

    # 计算后剪枝ccp
    # path = tree_clf.cost_complexity_pruning_path(x_train, y_train)
    # ccp_alphas, impurities = path.ccp_alphas, path.impurities
    # clfs = []
    # for ccp_alpha in ccp_alphas:
    #     clf = DecisionTreeClassifier(random_state=0, ccp_alpha=ccp_alpha)
    #     clf.fit(x_train, y_train)
    #     clfs.append(clf)
    
    # ccp_alpha_show(clfs, x_train, y_train, x_test, y_test, ccp_alphas)



def ccp_alpha_show(clfs, x_train, y_train, x_test, y_test, ccp_alphas):
    # 绘制ccp_alpha与深度的关系
    clfs = clfs[:-1]
    ccp_alphas = ccp_alphas[:-1]
    node_counts = [clf.tree_.node_count for clf in clfs]
    depth = [clf.tree_.max_depth for clf in clfs]
    fig, ax = plt.subplots(2, 1)
    ax[0].plot(ccp_alphas, node_counts, marker="o", drawstyle="steps-post")
    ax[0].set_xlabel("alpha")
    ax[0].set_ylabel("number of nodes")
    ax[0].set_title("Number of nodes vs alpha")
    ax[1].plot(ccp_alphas, depth, marker="o", drawstyle="steps-post")
    ax[1].set_xlabel("alpha")
    ax[1].set_ylabel("depth of tree")
    ax[1].set_title("Depth vs alpha")
    fig.tight_layout()
    plt.show()

    #绘制ccp_alpha与精度的关系
    train_scores = [clf.score(x_train, y_train) for clf in clfs]
    test_scores = [clf.score(x_test, y_test) for clf in clfs]

    fig, ax = plt.subplots()
    ax.set_xlabel("alpha")
    ax.set_ylabel("accuracy")
    ax.set_title("Accuracy vs alpha for training and testing sets")
    ax.plot(ccp_alphas, train_scores, marker="o", label="train", drawstyle="steps-post")
    ax.plot(ccp_alphas, test_scores, marker="o", label="test", drawstyle="steps-post")
    ax.legend()
    plt.show()

def main():
    pre_data()
    # train_data = label_encode()
    # data_show(train_data)
    # data_show(raw_data)
    # for i in range(1,20):
    #     print(f"*************深度：{i}************\n")
    
    k_cross_validation()   # K折交叉验证
    hold_out(0.3)             # 留出法
    show()

main()