/*现有一个无向图G=(V,E),其顶点集合和邻接矩阵是
char V[]={‘A',’B’,’C’,’D’,’E’,’F’,’G’};
char Adj[7][7]={
0, 1, 0, 1, 0, 0, 0,
1, 0, 1, 0, 1, 0, 1,
0, 1, 0, 1, 1, 0, 0,
1, 0, 1, 0, 1, 1, 0,
0, 1, 1, 1, 0, 0, 0,
0, 0, 0, 1, 0, 0, 0,
0, 1, 0, 0, 0, 0, 0
  };
请填写起点B开始的深度优先和宽度优先访问的结点序列字符串（用一行填写，前面是深度\
优先，后面是宽度优先，之间用-链接，如ABCDEFG-ABCDEFG）。访问一个结点的多个邻接顶点时，按它们在顶点表\\
的位置顺序。
 输入描述
 输出描述
 输入样例
 输出样例*/
#include <iostream>       
#include <string>    
#include <queue>  
using namespace std;      
  
typedef char vertexType;    //顶点的数据类型，这里姑且设为字符，A,B,C,D  
typedef int edgeType;   //边的信息，姑且定位权值  
#define MAXVEX 100  //最大顶点数  
bool visited[MAXVEX];   //访问标记  
  
struct MGraph   //图结构  
{  
    vertexType vexs[MAXVEX];    //顶点数组  
    edgeType arc[MAXVEX][MAXVEX];   //边信息，邻接矩阵  
    int numVertex, numEdge; //顶点数，边数  
};  
  
void createMGraph(MGraph* G)  
{  
    cout << "请输入顶点数，边数：";  
    cin >> G->numVertex >> G->numEdge;  
    cout << "请输入每个顶点的字母表示：";  
    for (int i = 0; i < G->numVertex; i++)  
    {  
        cin >> G->vexs[i];  
    }  
    for (int i = 0; i < G->numVertex; i++)  
    {  
        for (int j = 0; j < G->numVertex; j++)  
        {  
            G->arc[i][j] = INT_MAX; //边上权值初始化为正无穷，表示顶点不相邻  
        }  
    }  
    cout << "请输入每条边的起点序号，终点序号，和边的权值：";  
    for (int i = 0; i < G->numEdge; i++)  
    {  
        int start, end, weight;  
        cin >> start >> end >> weight;  
        G->arc[start][end] = weight;  
        G->arc[end][start] = weight;  
    }  
}  
  
void DFS(MGraph G, int i)  
{  
    visited[i] = true;  
    cout << G.vexs[i] << " ";  
    for (int j = 0; j < G.numVertex; j++)  
    {  
        if (G.arc[i][j] != INT_MAX && !visited[j])  
        {  
            DFS(G, j);  
        }  
    }  
}  
  
void DFSTraverse(MGraph G)  
{  
    for (int i = 0; i < G.numVertex; i++)  
    {  
        visited[i] = false;  
    }  
    for (int i = 0; i < G.numVertex; i++)  
    {  
        if (!visited[i])  
        {  
            DFS(G, i);  
        }  
    }  
}  
  
void BFSTraverse(MGraph G)  
{  
    queue<int> que;  
    for (int i = 0; i < G.numVertex; i++)  
    {  
        visited[i] = false;  
    }  
    for (int i = 0; i < G.numVertex; i++)  
    {  
        if(!visited[i])  
        {  
            visited[i] = true;  
            cout << G.vexs[i] << " ";  
            que.push(i);  
            while(!que.empty())  
            {  
                int t = que.front();  
                que.pop();  
                for (int j = 0; j < G.numVertex; j++)  
                {  
                    if (G.arc[t][j] != INT_MAX && !visited[j])  
                    {  
                        visited[j] = true;  
                        cout << G.vexs[j] << " ";  
                        que.push(j);  
                    }  
                }  
            }  
        }  
    }  
}  
  
int main()      
{      
    MGraph G;  
    createMGraph(&G);  
    cout << "DFS访问顶点顺序:   ";  
    DFSTraverse(G);  
    cout << endl;  
    cout << "BFS访问顶点顺序:   ";  
    BFSTraverse(G);  
    cout << endl;  
    return 0;    
}  
 
