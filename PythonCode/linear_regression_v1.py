import random
import torch
from torch.utils import data
from d2l import torch as d2l
from torch import nn

def synthetic_data(w, b, num_examples):  #@save
    """生成 y = Xw + b + 噪声。"""
    X = torch.normal(0, 1, (num_examples, len(w)))
    print(X)
    y = torch.matmul(X, w) + b
    y += torch.normal(0, 0.01, y.shape)
    return X, y.reshape((-1, 1))

""" 函数参数用*，** 分别表示可以接受多个参数形成列表或字典；
    函数调用用*，** 表示可以将列表或字典自动解析成单个字符；
    过程可逆。
"""
def load_array(data_arrays, batch_size, is_train=True):  #@save
    """构造一个PyTorch数据迭代器。"""
    dataset = data.TensorDataset(*data_arrays)       
    return data.DataLoader(dataset, batch_size, shuffle=is_train)

true_w = torch.tensor([2, -3.4])
true_b = 4.2
features, labels = d2l.synthetic_data(true_w, true_b, 1000)

batch_size = 10
data_iter = load_array((features, labels), batch_size)

""" 定义模型，并指定权重和偏置"""
net = nn.Sequential(nn.Linear(2, 1))    #（2，1）分别指输入和输出的特征形状
net[0].weight.data.normal_(0, 0.01)     # net[0] 选择网络中第一个图层
net[0].bias.data.fill_(0)

loss = nn.MSELoss()    # 损失函数
trainer = torch.optim.SGD(net.parameters(), lr=0.03)     #优化算法

num_epochs = 3
# 训练
for epoch in range(num_epochs):
    for X, y in data_iter:
        l = loss(net(X) ,y)
        trainer.zero_grad()
        l.backward()
        trainer.step()
    l = loss(net(features), labels)
    print(f'epoch {epoch + 1}, loss {l:f}')

w = net[0].weight.data
print('w的估计误差：', true_w - w.reshape(true_w.shape))
b = net[0].bias.data
print('b的估计误差：', true_b - b)

