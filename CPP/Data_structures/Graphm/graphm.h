#include <iostream>
#include "graph.h"
#include "book.h"

#define MAX_VERTEX_NUM 40
#define UNVISITED 0
#define VISITED 1
using namespace std;

template <typename VertexType>
class Graphm : public Graph<VertexType> {
private:
  int numVertex, numEdge; //�������ͱ���
	bool undirected;  // true if graph is undirected, false if directed
	VertexType vexs[MAX_VERTEX_NUM];	//�洢������Ϣ 
	
  int **matrix;           // Pointer to adjacency matrix
  int *mark;              // Pointer to mark array
public:
  Graphm(int numVert)     // Constructor
    { Init(numVert); }

  ~Graphm() {       // Destructor
  	cout<<"gramat delete";
    delete [] mark; // Return dynamically allocated memory
    for (int i=0; i<numVertex; i++)
      delete [] matrix[i];
    delete [] matrix;
  }

  void Init(int n) { // Initialize the graph
    int i;
    numVertex = n;
    numEdge = 0;
    mark = new int[n];     // Initialize mark array
    for (i=0; i<numVertex; i++)
      mark[i] = UNVISITED;
    matrix = (int**) new int*[numVertex]; // Make matrix
    for (i=0; i<numVertex; i++)
      matrix[i] = new int[numVertex];
    for (i=0; i< numVertex; i++) // Initialize to 0 weights
      for (int j=0; j<numVertex; j++)
        matrix[i][j] = 0;
  }

  int n() { return numVertex; } // Number of vertices
  int e() { return numEdge; }   // Number of edges

  // Return first neighbor of "v"
  int first(int v) {
    for (int i=0; i<numVertex; i++)
      if (matrix[v][i] != 0) return i;
    return numVertex;           // Return n if none
  }

  // Return v's next neighbor after w
  int next(int v, int w) {
    for(int i=w+1; i<numVertex; i++)
      if (matrix[v][i] != 0)
        return i;
    return numVertex;           // Return n if none
  }
  //����ͼ�����ͣ�����ͼ������ͼ��
	void setType(bool flag){
		undirected=flag;
	}
	//��ȡͼ������
	bool getType(){
		return undirected;
	}
	/**���ض�����ͼ�е�λ��**/ 
	int locateVex(VertexType u){
		for(int i=0;i<numVertex;i++){
			if(Comp(u,vexs[i]))	//Compģ�庯��д��book.h�� 
				return i;
		}
		return -1;
	}
	/**����ĳ�������ֵ(ʵ����Ϣ) **/ 
	VertexType getVex(int v){
		return vexs[v];
	} 
  /**��ĳ�����㸳ֵ**/
	void putVex(int v,VertexType value){
		vexs[v]=value;
	}
		
  // Set edge (v1, v2) to "wt"
  void setEdge(int v1, int v2, int wt) {
    Assert(wt>0, "Illegal weight value");
    if (matrix[v1][v2] == 0) 
			numEdge++;
    matrix[v1][v2] = wt;
    if(undirected){
    	matrix[v2][v1] = wt;
		}  
  }

  void delEdge(int v1, int v2) { // Delete edge (v1, v2)
    if (matrix[v1][v2] != 0){
    	numEdge--;
    	matrix[v1][v2] = 0;
    	if(undirected){
    		matrix[v2][v1] = 0;
			}  
		}
  }

  bool isEdge(int i, int j) // Is (i, j) an edge?
  { return matrix[i][j] != 0; }

  int weight(int v1, int v2) { return matrix[v1][v2]; }
  int getMark(int v) { return mark[v]; }
  void setMark(int v, int val) { mark[v] = val; }
};
