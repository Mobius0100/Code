#include<iostream>
#include<cstring>
#include "graphm.h"
#include "graph.h"
#include "create.h" 
using namespace std;

int main(){
	//now let's create our graph
	//we read info from the textfile 
	FILE *fid;
	int k;
	fid = fopen("test.gph", "rt");
	Graph<string>* G;
	G = createGraph(fid);

	// int m,n;
	// int v1,v2,value;
	// cin >> n >> m;
	// G = new Graphm<string>(n);
	// for(int i=0; i<m; i++){
	// 	cin >> v1 >> v2 >> value;
	// 	G->setEdge(v1, v2, value);
	// 	G->setEdge(v2, v1, value);
	// } 
	Gprint(G);
	return 0;
}
