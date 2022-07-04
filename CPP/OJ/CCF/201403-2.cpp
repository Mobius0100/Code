/*
	:模拟点击窗口程序，给定窗口坐标，点击坐标，判断该点击中哪个窗口，将其置顶并输出窗口号，如没有点中，输出IGNORE
	思路：将矩形定义为结构体，按从底向上的顺序存入vector，然后从末尾向前遍历，点中窗口将其窗口号输出，并删除后再重新存入可以模拟置顶过程
*/
#include <bits/stdc++.h>

using namespace std;

const int Maxn = 100;

struct Rect{
	int x1,y1;
	int x2,y2;
	int rank;
}temp;

vector<Rect> rec;

int main()
{
	int N,M;
	cin >> N >> M;
	temp.x1 = 0,temp.x2 = 0,temp.y1=0,temp.y2 = 0,temp.rank=0;    //用于改变下标
	rec.push_back(temp);
	for(int i=1;i<=N;i++){
		cin >> temp.x1 >> temp.y1 >> temp.x2 >> temp.y2;
		temp.rank = i;
		rec.push_back(temp);
	}
	
	int x,y;
	for(int i=0;i<M;i++){
		cin >> x >> y;
		int flag = 1;
		for(int j=N;j>0;j--){
			temp = rec[j];
			if(x>=temp.x1 && x <= temp.x2 && y >= temp.y1 && y <= temp.y2){    //有选中的窗口
				flag = 0;
				cout << temp.rank << endl;    //输出窗口号
				rec.erase(rec.begin() + j);     //删除
				rec.push_back(temp);         //置顶
				break;
			}
		}
		if(flag) cout << "IGNORED" << endl;
	}
	
	return 0; 
}
