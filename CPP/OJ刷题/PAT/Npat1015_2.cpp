#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100010
int n=0,k;
struct Node{
	int id,data,next,order=maxn;
}node[maxn];
bool cmp(Node a,Node b){
	return a.order<b.order;
}
bool cmp_reverse(Node a,Node b){
	return a.order>b.order;
}
int main(){
	//freopen("A1074.txt","r",stdin);
	int N,head;
	scanf("%d%d%d",&head,&N,&k);
	while(N--){
		int temp;
		scanf("%d",&temp);
		scanf("%d%d",&node[temp].data,&node[temp].next);
		node[temp].id=temp;
	}
	int p=head;
	while(p!=-1){
		node[p].order=n+1;
		p=node[p].next;
		n++;
	}
	sort(node,node+maxn,cmp);
	int r=n,i=0;
	while(r>=k){
		sort(node+i*k,node+i*k+k,cmp_reverse);
		r=r-k;
		i++;
	}
	for(int i=0;i<n;i++){
		printf("%05d %d ",node[i].id,node[i].data);
		if(i<n-1)printf("%05d\n",node[i+1].id);
		else printf("-1");
	}
	return 0;
}
