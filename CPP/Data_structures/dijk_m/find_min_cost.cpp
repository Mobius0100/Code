#include <iostream>
#include <cstring>
#include "graphm.h"
#include "graph.h"
#include "create.h"
#include <cmath>

using namespace std;
int minVertex(Graph<string>*, double*);

// Compute shortest path distances from "s".
// Return these distances in "D".
void Dijkstra(Graph<string>* G, double* D) {
  int i, v, w;
  for (i=0; i<G->n(); i++) {      // Process the vertices
    v = minVertex(G, D);
    if (D[v] == -1) return; // Unreachable vertices
    G->setMark(v, VISITED);
    for (w=G->first(v); w<G->n(); w = G->next(v,w))
    {
      if (D[w] < (D[v] * G->weight(v, w)))
        {
          D[w] = D[v] * G->weight(v, w);
        }
    }
  }
}

int minVertex(Graph<string>* G, double* D) { // Find min cost vertex
  int i, v = -1;
  // Initialize v to some unvisited vertex
  for (i=0; i<G->n(); i++)
    if (G->getMark(i) == UNVISITED) { v = i; break; }
  for (i++; i<G->n(); i++)  // Now find smallest D value
    if ((G->getMark(i) == UNVISITED) && (D[i] > D[v]))
      v = i;
  return v;
}

int main(){
  int m,n;
  int x1, x2, x3;
  cin >> n >> m;

	
  //新建一个图
	Graph<string>* G = new Graphm<string>(n);
  //设置为无向图
  G->setType(true);
  //初始化顶点信息
  for(int i=0; i < n; i++){
    G->putVex(i, to_string(i));
  }

  //将边权转换为扣税百分比
  for(int i=0; i<m; i++){
    cin >> x1 >> x2 >> x3;
    double x = (100.0 - x3) / 100;
    G->setEdge(x1-1, x2-1, x);
  }
  

  //D用于表示起点到目标顶点的最小路径
	double D[G->n()];
  for (int i=0; i<G->n(); i++){
    D[i] = -1;
  }

  cin >> x1 >> x2;
  //  打印图便于调试
  // Gprint(G);
	D[x1-1] = 1;

  // 使用Dijkstra算法查找最短路径
	Dijkstra(G, D);

  //  输出答案
  double ans = 100.0/D[x2-1];
  ans = floor(ans * 100000000)/100000000;
  printf("%.8lf",ans);
	
	return 0;
}
