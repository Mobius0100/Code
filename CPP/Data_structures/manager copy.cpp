#include <iostream>
#include <cstring>
#include "graphm.h"
#include "graph.h"
#include "create.h"
#define INFINITY 9999

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
  cout.precision(8);
	
	Graph<string>* G = new Graphm<string>(n);
  G->setType(true);
  for(int i=0; i < n; i++){
    G->putVex(i, to_string(i));
  }

  for(int i=0; i<m; i++){
    cin >> x1 >> x2 >> x3;
    double x = (100.0 - x3) / 100;
    G->setEdge(x1-1, x2-1, x);
  }
  


	double D[G->n()];
  for (int i=0; i<G->n(); i++){
    D[i] = -1;
  }

  cin >> x1 >> x2;
  // Gprint(G);
	D[x1-1] = 1;

	Dijkstra(G, D);
  // for (int i=0; i<G->n(); i++){
  //   printf("%.8lf ",D[i]);
  //   // cout << D[i] << " ";
  // }
  // cout << endl;
  printf("%.8lf",100.0/D[x2-1]);
	
	return 0;
}
