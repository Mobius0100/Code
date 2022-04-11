[TOC]



# CCF真题

## 201809-2 买菜

**超过10W的数组长度需要申请内存或定义全局变量数组**

建立一个时间数组，分别判断两个人是否在这个时间点上，是加一，都在则为2，为2的时间点即为聊天时间

~~~c
#include <stdio.h>
int t[1000000];

int main()
{
	int n,count=0,i,j,a,b,max=0;

	scanf("%d",&n);
	
	for(i=0;i<2*n;i++)
	{
		scanf("%d%d",&a,&b);
		if(b>max) max=b;
		for(j=a;j<b;j++) t[j]++;
	} 
	
	for(i=0;i<max;i++)
	{
		if(t[i]==2) count++;
	}
	
	printf("%d",count);
	
	return 0;
}
~~~



## 201712-2 游戏

map的使用：第一个参数 function 以参数序列中的每一个元素调用 function 函数，返回包含每次 function 函数返回值的迭代器。

~~~python
n,k = map(int,input().split())
li = list(range(1,n+1))
t = 1

while len(li) > 1:
    dellist = []
    for i in li:
        if t%k==0 or t%10==k:
            dellist.append(i)
        t += 1

    for i in dellist:
        li.remove(i)
        if len(li)==1:
            print(li[0])
~~~

## 201703-2 学生排队

列表的insert()方法和index方法

列表按字符串输出

~~~python
n = eval(input())
m = eval(input())
li = []

li = list(range(1,n+1))

for i in range(m):
    stu,pos = map(int,input().split())
    after = list.index(stu) + pos
    list.remove(stu)
    list.insert(after,stu)

print(' '.join(map(str,list)))
~~~



C++:

~~~c++
#include <stdio.h>

const int maxn = 1005;

int q[maxn] = {0};

int find_pos(int num)
{
	for(int i=0;i<maxn;i++)
	{
		if(q[i] == num)	return i;
	}	
}

int main()
{
	int n,m;
	scanf("%d%d",&n, &m);
	for(int i=1;i<=n;i++) q[i] = i;
	
	int sno, pos;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&sno, &pos);
		int pos1 = find_pos(sno);
		if(pos >= 0) 
		{
			for(int j=pos1;j<pos1+pos;j++)
				q[j] = q[j+1];
			q[pos1+pos] = sno;
		}
		else
		{
			for(int j=pos1;j>pos1+pos;j--)
				q[j] = q[j-1];
			q[pos1+pos] = sno;
		}
	}
	
	for(int i=1;i<=n;i++) printf("%d ",q[i]);
	
	return 0; 
}
~~~



## 201809-1 买菜

//表示整数除法，/表示浮点数除法

~~~python
n = eval(input())
price = list(map(int, input().split()))

price_2 = []
price_2.append((price[0] + price[1]) // 2)
for i in range(1, n - 1):
    price_2.append((price[i - 1] + price[i] + price[i + 1]) // 3)
price_2.append((price[n-1] + price[n-2]) // 2)

print(' '.join(map(str,price_2)))
~~~

## 201712-1 最小差值

lambda结合map 的用法

列表的排序sort()方法

min()的方法

~~~python
n = eval(input())
l = list(map(int, input().split()))

l.sort()
diff = list(map(lambda x,y:y-x,l[:-1],l[1:]))
print(min(diff))
~~~

```c++
#include <stdio.h>
#include <algorithm>
#include <math.h>

#define maxn 1005

using namespace std;
int num[maxn];

int main()
{
	int n,t1=1000000,t2;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	for(int i=0;i<n-1;i++)
	{
		t2 = abs(num[i] - num[i+1]);
		if(t2 < t1) t1 = t2;
		if(t1 == 0) break;
	}
	
	printf("%d",t1);
	return 0;
}
```



## 201612-1 中间数

折中查找法

~~~python
n = eval(input())
l = list(map(int, input().split()))
l.sort()

middle = n//2
after = n//2
before = n//2

while before>0 and l[middle] == l[before - 1]:
    before -= 1
while after < n-1 and l[middle] == l[after + 1]:
    after += 1

if before == (n-1-after):
    print(l[middle])
else:
    print(-1)
~~~

```c++
#include <stdio.h>
#include <algorithm>

using namespace std;
#define maxn 1005
int num[maxn];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	int big=-1,small=-2;
	for(int i=n/2;i<n-1;i++)
	{
		if(num[n/2] != num[i+1]) 
		{
			big = n-i-1;
			break;
		}
	}
	for(int i=n/2;i>0;i--)
	{
		if(num[n/2] != num[i-1]) 
		{
			small = i;
			break;
		}
	}
	if(big == small) printf("%d",num[n/2]);
	else printf("-1");
	return 0;
}
```



## 201609-1 最大波动

python 实现问号表达式:   x = a if () else b     ==>  x = () ?  a:b;

~~~python
n = eval(input())
l = list(map(int, input().split()))

diff = list(map(lambda x,y:abs(y-x),l[:-1],l[1:]))

print(max(diff))
###法2
wave_max=0
for i in range(1,n):#取差值最大的
    wave_max = abs(a[i]-a[i-1]) if (abs(a[i]-a[i-1])>wave_max) else wave_max

~~~

## 201512-1 数位之和

给定一个十进制整数*n*，输出*n*的各位数字之和。

sum()方法,又是map

~~~python
print(sum(map(int,input())))
~~~

## 201503-1 图像旋转

print中，以end=‘‘ 以’‘内的字符串结尾代替换行

~~~python
#图像旋转
n,m = map(int,(input().split()))
img = []
for i in range(n):
    a = list(map(int,input().split()))
    img.append(a)
for i in range(m):
    for j in range(n):
        print(img[j][m-1-i],end=" ")
    print()
~~~

```c++
#include <stdio.h>
#include <string.h>

#define maxn 1005
int num[maxn][maxn];

int main()
{
	int n,m,count=0,k;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&num[i][j]);
		}
	}
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",num[j][m-i-1]);
		}
		printf("\n");
	}
	return 0;
}
```

## 201412-1 门禁系统

按编号统计次数，可建立一个新列表，原列表的值作为新列表的索引

~~~python
n = eval(input())
record = list(map(int,input().split()))

t = [1]*n
for i in record:
    print(t[i],end=' ')
    t[i] += 1
~~~

## 201409-1 相邻数对

与数字大小有关可考虑先排序

~~~python
n = eval(input())
li = list(map(int,input().split()))

count = 0
for i in range(n):
    for j in range(i+1,n):
        if abs(li[i]-li[j])==1:
            count += 1
print(count)
#方法二（先排序，更快）
#相邻数对
n = int(input())
a = list(map(int,input().split()))
a.sort()#排序
count=0
for i in range(n-1):
    if(a[i+1]-a[i] == 1):#相差为一
        count+=1
print(count)

~~~

## 201403-1 相反数

set方法用于得到无序，无重复元素的集合

~~~python
#相反数
n = int(input())
a = list(map(int,input().split()))#输入转化为列表
b = set(map(abs,a))#各项取绝对值后转化为集合，即除去相反的负数
print(len(a)-len(b))#原长度减去现长度，即被减去的相反数个数
~~~

```c++
#include <stdio.h>

#define maxn 10005
int num[maxn];

int main()
{
	int n,count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(num[i] == -num[j]) count++;
		}	
	}
	
	printf("%d",count);
	return 0;
}
```



## 201312-1 出现最多的次数

**index方法返回查找对象的索引位置，如果没有找到对象则抛出异常。**

**count方法统计该字符出现的个数**

字典的get方法，d.get( ) /key = d.get
返回指定键的值

~~~python
n = int(input())
a = list(map(int,input().split()))
# 排序函数 sort()
a.sort()
b = []
for i in range(n):
	# 计数函数 count()
    b.append(a.count(a[i]))
    # 索引函数 index() 检测字符串中是否包含子字符串 str ，并返回其位置
    pos_max = b.index(max(b))
print(a[pos_max])

#方法二
#出现次数最多的数
n = int(input())
a = list(map(int,input().split()))
b = list(set(a))#化为集合，去掉相同数
b.sort()#从小到大排序
s = dict(zip(b,map(a.count,b)))#将数与它的出现次数组合再转为字典
print(max(s,key=s.get))#根据字典值选出count最大的数
 
~~~

```c++
#include <stdio.h>
#include <string.h>

#define maxn 10005
int num[maxn];

int main()
{
	int n,max=0,max_index=0,k;
	memset(num, 0, sizeof(num));
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		num[k]++;
	}
	
	for(int i=0;i<maxn;i++)
	{
		if(num[i] > max)
		{
			max_index = i;
			max = num[i];
		}
	}
	
	printf("%d\n",max_index);
	
	return 0;
}
```



## 201609-2 火车购票

列表的分割:5 6 7行

4行的列表赋值形式

~~~python
n = eval(input())
li = list(map(int, input().split()))

l1 = [i for i in range(1,101)]
l2 = []
for i in range(20):
    l2.append(l1[i*5:i*5+5])
# 形式二:
# l2 = [l1[i*5:i*5+5] for i in range(20)]

for i in li:
    for j in l2:
        if i<=len(j):
            print(' '.join(map(str,j[:i])))
            flag = 0
            for k in range(i):
                j.pop(0)
            break
        else:
            flag = 1
    if flag: ##没有连续座位
        for j in l2:
            print(' '.join(map(str,j[:i])),end=' ')
            i -= len(j)
            if i == 0:
                break

~~~

## 201512-2 消除类游戏

**借用新数组进行标记**

~~~python
n,k = map(int,input().split())

l2 = []
for i in range(n):
    l1 = list(map(int,input().split()))
    l2.append(l1)

sign = [[0]*k for i in range(n)]
for i in range(n):
    for j in range(1,k-1):
        if l2[i][j-1]==l2[i][j] and l2[i][j] == l2[i][j+1]:
            sign[i][j-1] = 1
            sign[i][j] = 1
            sign[i][j+1] = 1

for i in range(k):
    for j in range(1,n-1):
        if l2[j-1][i]==l2[j][i] and l2[j][i] == l2[j+1][i]:
            sign[j-1][i] = 1
            sign[j][i] = 1
            sign[j+1][i] = 1

for i in range(n):
    for j in range(k):
        if sign[i][j]:
            l2[i][j] = 0

for i in range(n):
    print(' '.join(map(str,l2[i])))
~~~

## 201503-2 数字排序

###  字典

sorted 配合字典items()返回键值对列表 再以lambda函数 选择 值(键)排序

sorted与sort的区别在于:返回新的列表

count(i)  统计该数在列表中的个数

~~~python
n = eval(input())
num = list(map(int, input().split()))

num.sort()
dic = {}

for i in num:
    dic[i] = num.count(i)   #字典的赋值添加

dic2 = sorted(dic.items(),key=lambda item:item[1],reverse=True)

for i in dic2:
    print(i[0],i[1])
~~~



~~~c++
#include <stdio.h>
#include <algorithm>

const int maxn=1005;

using namespace std;

struct num{
	int cnt,value;
}nums[maxn];

bool cmp(num a, num b)
{
	if(a.cnt != b.cnt) return a.cnt > b.cnt;
	else return a.value < b.value;
}

int main()
{
	int n,t;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		nums[t].cnt++;
		nums[t].value = t;
	}
	
	sort(nums, nums+maxn, cmp);
	for(int i=0;i<n;i++)
	{
		if(nums[i].cnt != 0)
			printf("%d %d\n",nums[i].value,nums[i].cnt);
	}
	
	return 0;
}
~~~

## 201509-2 日期计算

~~~c++
#include <stdio.h>

int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

bool isLeapYear(int year)
{
	if(year%400 == 0 || (year%4 == 0 && year%100 != 0)) return true;
	else return false;
}

int main()
{
	int y,d;
	scanf("%d%d",&y, &d);
	if(isLeapYear(y)) days[1]++;
	
	int i;
	for(i=0;i<12;i++)
	{
		if(d-days[i] > 0) d -= days[i];
		else break; 
	}
	
	printf("%d\n%d",i+1,d);
	
	return 0;
}
~~~



## 201409-2 画图

编程的技巧,标记已存在的面积,最后输出为1的面积

sum()为 列表之和

~~~python

#标记法
#画图
n = int(input())
pmap = [[0]*100 for _ in range(100)]#创建100*100的二维列表数组
for i in range(n):
    x1,y1,x2,y2 = map(int,(input().split()))
    for x in range(x1,x2):
        for y in range(y1,y2):
            pmap[x][y] = 1#矩形区域内标识为一
psum=0
for i in range(100):
    psum+=sum(pmap[i])
print(psum)#统计面积
~~~

C++/C: 暴力法：



~~~c++
#include <stdio.h>

int maps[100][100] = {0};

int main()
{
	int n;
	int x1,x2,y1,y2;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x1, &y1, &x2, &y2);
		for(int k=y1;k<y2;k++)
		{
			for(int j=x1;j<x2;j++)
			{
				maps[j][k] = 1;
			}
		}
	}
	
	int ans=0;
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			if(maps[i][j] == 1) ans++;
		}
	}
	
	printf("%d\n",ans);
} 
~~~



## 201312-2 ISBN号码

注意字符串与数字的转换方法,以及**字符串的修改**分割方法(切片)

~~~python
isbn=input()
#复制一份备用,只保留前9个数字
r_isbn=isbn[0]+isbn[2:5]+isbn[6:11]
#开始计算
num=0
for i in range(9):
    s=int(r_isbn[i])
    num+=(s*(i+1))
num%=11
#余数为10，需要判断最后一位是否等于x
if num==10:
    if isbn[-1]=='X':
        print('Right')
    else:
        print(isbn[0:-1]+'X')
#余数不为10，需要判断最后一位是否等于num
else:
    if isbn[-1]==str(num):
        print('Right')
    else:
        print(isbn[0:-1]+str(num))
        
        
#方法二
li = input()
num = []
for i in li[:-1]:
    if i.isdigit():    #判断字符串是否为数字
        num.append(int(i))
sign = 0
for i in range(9):
    sign += (num[i]*(i+1))

sign = sign%11
if li[-1] == str(sign) or (sign == 10 and li[-1] == 'X'):
    print('Right')
else:
    if sign==10:
        li = li[:-1] + 'X'
    else:
        li = li[:-1] + str(sign)
    print(li)
~~~

c++/c：

~~~c++
#include <stdio.h>
#include <string.h>

int main()
{
	char str[20];
	int num[20],sum=0,count=0;
	scanf("%s",str);
	
	int len = strlen(str);
	for(int i=0;i<len-1;i++)
	{
		if(str[i] != '-') num[count++] = str[i] - '0';
	}
	for(int i=0;i<count;i++)
	{
		sum += num[i]*(i+1);
	}
	
	char ans;
	sum = sum%11;
	if(sum == 10) ans = 'X';
	else ans = sum + '0';
	if(ans == str[len-1]) printf("Right");
	else
	{
		for(int i=0;i<len-1;i++) printf("%c",str[i]);
		printf("%c",ans);
	}
	
	return 0;
}
~~~



## 201604-2 俄罗斯方块

### 此题未解出，记得复习

思路：建立两个列表，每一行遍历一次板块并相加，如果相碰，则结果为2，上一行即为正确结果

~~~python
#俄罗斯方块
tmap = []#存储(15+3)行10列的方格图信息
 
#读取输入 
for i in range(15):
	tmap.append(list(map(int,input().split())))#从标准输入读取每行数据存入tmap
for i in range(3):
	tmap.append([1]*10)#再存入3行都是1的方格图信息，目的是方便下面循环，保证4行板块第一行对应15行方格图最后一行时行数最大为（15+4-1）不会越界
 
shape = []#存储板块信息
for i in range(4):
	shape.append(list(map(int,input().split())))#读入板块形状数据
x = int(input())#读入板块起始列
 
#板块数据根据起始列从4行4列扩展到4行10列
for i in range(4): 
	shape[i] = [0]*(x-1) + shape[i] + [0]*(10-4-(x-1))
	#每行左边0的个数(x-1)，右边0的个数(10-4-(x-1))。[0]*x意为列表[0,0,...]有x个0
 
right = 0#板块第一行最终落到的方格图行数
find = False#标记是否找到位置
 
#判断板块位置
for i in range(15):#遍历方格图所有行
	#从第i行开始检测方格图与板块是否已经碰撞
	for j in range(4):#遍历板块每一行
		newline = [a+b for a,b in zip(tmap[i+j],shape[j])]#将一行的方格图每项数据与板块每项数据相加生成新行
		if(2 in newline):#如果新行里出现了2，说明存在有位置方格图与板块对应数据都为1，即产生了碰撞
			right = i-1#第一次出现碰撞的上一行就是板块第一行最终落到的位置
			find = True#找到了
			break#退出里层循环
	if(i == 14):
		right=14#如果搜索到了最后一行，则直接确定行数
	if(find):#找到了位置就退出外层循环，没找到就让板块下降一格继续循环
		break
 
#拼接方格图与板块生成最终方格图数据
for j in range(4):
	tmap[right+j]= [a+b for a,b in zip(tmap[right+j],shape[j])]#相当于将板块信息置入方格图
	#zip（）函数将两个列表各项一一对应，for a,b in zip(...)遍历两个列表的每项分别为a,b ;[a+b for a,b in ...]将每项加起来生成新的列表
 
#输出数据
for i in range(15):
	print(" ".join(map(str,tmap[i])))#map(str,tmap[i])将tmap里所有的int数据转换成str字符串用于拼接，" ".join(...)将字符串列表每项中间加空格生成一个长的字符串
~~~

**C:**



~~~c++
#include <stdio.h>

int map[20][10], box[4][4];
int start;

int find_row()
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				if(map[j+i][start+k-1] + box[j][k] == 2) return i-1;
			}
		}
	}
}
int main()
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<10;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}	
	for(int i=15;i<20;i++)
	{
		for(int j=0;j<10;j++) map[i][j] = 1;
	}
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			scanf("%d",&box[i][j]);
		}
	}
	
	scanf("%d",&start);
	
	int row = find_row();
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			map[row+i][start+j-1] += box[i][j];
		 } 
	}
	
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<10;j++)
		{
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
	
	return 0;
 } 
~~~



## 201412-2 Z字形扫描

### 未解出 

~~~python
n = eval(input())

matrix = []
for i in range(n):
    matrix.append(list(map(int,input().split())))

li = []
x=0
y=0
up = True    #表示转向

for i in range(n*n):
    li.append(matrix[x][y])
    if up:#右上
        if y == n-1:
            x += 1
            up = False
        elif x == 0:
            y += 1
            up = False
        else:
            x -= 1
            y += 1
    else:#左下
        if x == n-1:
            y += 1
            up =True
        elif y == 0:
            x += 1
            up = True
        else:
            x += 1
            y -= 1
            
print(' '.join(map(str,li)))
~~~

## 201403-2 窗口

注意窗口的编号关系与列表的顺序关系 (相等)

以及原始编号与当前编号 (不相等)

~~~python
n,m = map(int,input().split())

coord = []
click = []
for i in range(n):
    coord.append(list(map(int,input().split())))
    coord[i].append(i+1)

for i in range(m):
    click.append(list(map(int,input().split())))

coord.reverse()
for i in click:
    x,y = i
    flag = 0
    for j in range(n):
        if (x>=coord[j][0] and x<=coord[j][2]) and (y>=coord[j][1] and y<=coord[j][3]):
            print(coord[j][4])
            t = coord.pop(j)
            coord.insert(0,t)
            flag = 1
            break
    if flag==0:
        print('IGNORED')

~~~

c++/c:



~~~c++
#include <stdio.h>
#include <algorithm>
#define maxn 100

using namespace std;

struct win{
	int x1,x2,y1,y2;
	int flag;
	int num;
}wins[maxn];

bool cmp(win a, win b)
{
	return a.flag > b.flag;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&wins[i].x1,&wins[i].y1, &wins[i].x2, &wins[i].y2);
		wins[i].flag = i+1; 
		wins[i].num = i+1;
	}
	
	int x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x, &y);
		sort(wins, wins+n, cmp);
		int j;
		for(j=0;j<n;j++)
		{
			if(x >= wins[j].x1 && x <= wins[j].x2 && y >= wins[j].y1 && y <= wins[j].y2)
			{
				printf("%d\n",wins[j].num);
				wins[j].flag = n+i+2;
				break;
			}
		}
		if(j>=n) printf("IGNORED\n");
	}
	
	return 0;
}
~~~



## 201709-2 公共钥匙盒

知识点:

 l.index(value)  -->查询值的索引

time = list(set(time))  ---> 集合去重/或者在添加元素时判断是否存在

字典的使用

box = list(range(1,n+1))    快速建立数列,不用循环

~~~python
'''自己修改版本'''
n,k = map(int,input().split())
te = []
num = []
time = []
for i in range(k):
    t = list(map(int,input().split()))
    te.append(t)
    time.append(t[1])
    time.append(t[1]+t[2])   

for i in range(n):
    num.append(i+1)
#同时还或者拿时需要按钥匙编号从小到大执行
#储存为一个列表,依次判断
take = []  
back = []
time = list(set(time))  # 去重
time.sort()

for i in time:
    for j in te:
        if j[1] == i:
            take.append(j[0])   

        if (j[1] + j[2]) == i:
            back.append(j[0])

    back.sort()
    for i in back:
        num[num.index(0)] = i
    back = []
    for i in take:
        num[num.index(i)] = 0
    take = []

print(' '.join(map(str,num)))

'''思路对照版本'''
n,k=input().split()
n,k=int(n),int(k)
#用一个数组course来存储wsc的信息.并且不存储课程上多久，直接存储课程结束的时间
#并且为了方便存储，将钥匙当作从0编号开始。
#total_T是为了存储可能出现的时间点（上课点和下课点）
course=[]
total_T=[]
for i in range(k):
    w,s,c=input().split()
    w,s,c=int(w),int(s),int(c)
    course+=[[w-1,s,s+c]]
    #如果时间点不在数组里，进行存储。如果在，则不存储
    if s not in total_T:
        total_T+=[s]
    if s+c not in total_T:
        total_T+=[s+c]
#建立钥匙的初始数组，如果钥匙被取出，则其值为-1
key=[]
for i in range(n):
    key+=[i]

#对时间节点进行排序。从课程开始到课程结束，一个节点一个节点走。
total_T.sort()
for time in total_T:
    ##
    #先还钥匙，并且按照钥匙编号从小到大还钥匙,将归还时间相同的钥匙先存放在一个数组cou里面
    cou=[]
    for c in course:
        if c[2]==time:
            cou+=[c]
    #按照钥匙号从小到大排列
    cou.sort(key=lambda x:x[0])
    #遍历钥匙挂钩，看哪个没钥匙就把归还的钥匙放在那里
    t=0
    for i in range(n):
        #找到钥匙槽为-1（空）的位置，将归还的钥匙从小到大放入
        if key[i]==-1 and t<len(cou):
            key[i]=cou[t][0]
            t+=1

    #接下来进行取钥匙的操作,取钥匙没有顺序要求，前后无所谓
    for c in course:
        if c[1]==time:
            #找到所需要的钥匙位置，将该位置置为0
            for i in range(n):
                if key[i]==c[0]:
                    key[i]=-1
                    break
#将key输出
print(key[0]+1,end='')
for i in range(1,n):
    print('',key[i]+1,end='')
    
''' 使用字典版本 '''
#公共钥匙盒
n,k = map(int,input().split())
taket = {}
returnt = {}
timeline = {}
for i in range(k):
    w,s,c = map(int,input().split())
    if(s not in timeline):#借钥匙
        timeline[s]=[]
    timeline[s] += [w]
    timeline[s].sort()
    if(s+c not in timeline):#还钥匙
        timeline[s+c]=[]
    timeline[s+c] += [-(n-w)]#方便排序,从小到大归还
    timeline[s+c].sort()
 
box = list(range(1,n+1))    
 
for t in sorted(timeline.keys()):
    for x in timeline[t]:
        if(x <= 0):#还钥匙
            box[box.index(0)] = n+x
        else:#借钥匙
            box[box.index(x)] = 0
print(" ".join(map(str,box)))       
~~~

~~~c++
#include <stdio.h>

int count[20];
int main()
{
	int n,num;
	scanf("%d",&n);
	for(int i=0;i<20;i++) count[i] = 5;
		
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);
		for(int j=0;j<20;j++)
		{
			if(num <= count[j])
			{
				int ticket;
				for(int k=1;k<=num;k++)
				{
					ticket = j*5+k+(5-count[j]);
					printf("%d ",ticket);
				}
				printf("\n");
				count[j] -= num;
				break;
			} 
		}
	}
    return 0;
}
~~~



## 201803-1 跳一跳

​	

```c++
#include <stdio.h>

int main()
{
	int sum=0,pre=-1,now,count=1;
	scanf("%d",&now);
	while(now)
	{
		if(now == 2 && pre == 2) 
		{
			count++;
			sum += 2*count;
		}
		else if(now == 1) 
		{
			sum++;
			count = 1;
		}
		else sum+=now;
		pre = now;
		scanf("%d",&now);
	}
	
	printf("%d",sum);
	
	return 0;
}
```

## 201709-1 打酱油

```c++
#include <stdio.h>
#include <algorithm>
#include <math.h>

#define maxn 1005

using namespace std;
int num[maxn];

int main()
{
	int count,m;
	scanf("%d",&m);
	count = m/10;
	if(m/50 > 0)
	{
		count += (m/50) * 2;
		if(m%50/30 > 0) 
		{
			count += (m%50/30);
		}
	}
	else if(m/30 > 0)
	{
		count += m/30;
	}
	
	printf("%d",count);
	return 0;
}
```

## 201712-02 碰撞的小球

```C++
#include <stdio.h>
#define maxn 1000
 
int main()
{
	int ball[maxn]={0},step[maxn]={0};
	int L,n,t;
	scanf("%d%d%d",&n,&L,&t);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ball[i]);
		step[i] = 1;
		if(ball[i] == L) step[i] = -step[i];
	}
	
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<n;j++)
		{
			ball[j] += step[j];
			if(ball[j] == 0 || ball[j] == L) step[j] = -step[j];
		}
		
		for(int j=0;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(ball[k] == ball[j]) 
				{
					step[j] = -step[j];
					step[k] = -step[k];
				}
			}
		} 

	} 
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",ball[i]);	
	}
	
	
	return 0;
}
```



