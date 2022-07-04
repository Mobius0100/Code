import numpy as np
import pandas as pd
from sklearn.preprocessing import MinMaxScaler
from sklearn.tree import DecisionTreeClassifier
import matplotlib.pyplot as plt
from sklearn.tree import plot_tree
from sklearn.model_selection import train_test_split, KFold
import seaborn as sns
#引入数据集
df = pd.read_csv('iris.csv')

#决策树模型
data = df[['sepal_length','sepal_width', 'petal_length','petal_width']]
target = df['species']
tree_clf = DecisionTreeClassifier(criterion="entropy", max_depth=3)

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
    # show()
    sns.pairplot(data=df, diag_kind='hist', hue= 'species')
    plt.show()

def split_data():
    x_train , x_test, y_train, y_test = train_test_split(data.to_numpy(), target.to_numpy(), random_state=32)
    return x_train , x_test, y_train, y_test

def train(x_train, x_test, y_train, y_test):
    tree_clf.fit(x_train, y_train)
    score = tree_clf.score(x_test, y_test)
    print(score)

def hotmap(train):
    colormap = plt.cm.viridis
    plt.figure(figsize=(12,12))
    plt.title('Pearson Correlation of Features', y=1.05, size=15)
    sns.heatmap(train.astype(float).corr(),linewidths=0.1,vmax=1.0, square=True, cmap=colormap, linecolor='white', annot=True)
    plt.show()

def show():
    fn=['Sepal Length(cm)','Sepal_Width(cm)','Petal_Length(cm)','Petal_Width(cm)']
    cn=['setosa', 'versicolor', 'virginica']

    plt.figure(figsize=(12,8))
    plot_tree(tree_clf,
            feature_names = fn,
            class_names=cn,
            filled=True)
    plt.show()

def main():
    x_train , x_test, y_train, y_test = train_test_split(data.to_numpy(), target.to_numpy(), test_size=0.2)
    # k_cross_alidation()
    # train2(x_train , x_test, y_train, y_test)
    hotmap(data)

main()