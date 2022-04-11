/*
*/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;

struct Node{
    int addr;
    int next;
    int data;
    int order;
}node[maxn];

bool cmp(Node a,Node b){
    return a.order < b.order;
}
int main()
{
    int addr1,N,K,tmp;
    cin >> addr1 >> N >> K;

    for(int i=0;i<maxn;i++) node[i].order = maxn;
    for(int i=0;i<N;i++){
        cin >> tmp;
        cin >> node[tmp].data >> node[tmp].next;
        node[tmp].addr = tmp;
    }

    // for(int i=0;i<N;i++){
    //     node[addr1].order = i;
    //     addr1=node[addr1].next;
    // }

    int p = addr1,count=0;
    while(p != -1){
        node[p].order = count++;
        p = node[p].next;
    }

    sort(node,node+maxn,cmp);

    N = count;

    for(int i=0;i<N/K;i++){
        for(int j=(i+1)*K - 1;j> i*K;j--){
            printf("%05d %d %05d\n",node[j].addr,node[j].data,node[j-1].addr);
        }
        printf("%05d %d ",node[i*K].addr,node[i*K].data);
        if(i < N/K -1){
            printf("%05d\n",node[(i+2)*K - 1].addr);
        } else {
            if(N % K == 0){
                printf("-1\n");
            } else {
                printf("%05d\n",node[(i+1)*K].addr);
                for(i=(i+1) * K;i<N;i++){
                    printf("%05d %d ",node[i].addr,node[i].data);
                    if(i<N-1){
                        printf("%05d\n",node[i+1].addr);
                    } else {
                        printf("-1\n");
                    }
                }
            }
        }
    }



    return 0;
}
