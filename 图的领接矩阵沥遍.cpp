/*����һ������ͼG=(V,E),�䶥�㼯�Ϻ��ڽӾ�����
char V[]={��A',��B��,��C��,��D��,��E��,��F��,��G��};
char Adj[7][7]={
0, 1, 0, 1, 0, 0, 0,
1, 0, 1, 0, 1, 0, 1,
0, 1, 0, 1, 1, 0, 0,
1, 0, 1, 0, 1, 1, 0,
0, 1, 1, 1, 0, 0, 0,
0, 0, 0, 1, 0, 0, 0,
0, 1, 0, 0, 0, 0, 0
  };
����д���B��ʼ��������ȺͿ�����ȷ��ʵĽ�������ַ�������һ����д��ǰ�������\
���ȣ������ǿ�����ȣ�֮����-���ӣ���ABCDEFG-ABCDEFG��������һ�����Ķ���ڽӶ���ʱ���������ڶ����\\
��λ��˳��
 ��������
 �������
 ��������
 �������*/
#include <iostream>       
#include <string>    
#include <queue>  
using namespace std;      
  
typedef char vertexType;    //������������ͣ����������Ϊ�ַ���A,B,C,D  
typedef int edgeType;   //�ߵ���Ϣ�����Ҷ�λȨֵ  
#define MAXVEX 100  //��󶥵���  
bool visited[MAXVEX];   //���ʱ��  
  
struct MGraph   //ͼ�ṹ  
{  
    vertexType vexs[MAXVEX];    //��������  
    edgeType arc[MAXVEX][MAXVEX];   //����Ϣ���ڽӾ���  
    int numVertex, numEdge; //������������  
};  
  
void createMGraph(MGraph* G)  
{  
    cout << "�����붥������������";  
    cin >> G->numVertex >> G->numEdge;  
    cout << "������ÿ���������ĸ��ʾ��";  
    for (int i = 0; i < G->numVertex; i++)  
    {  
        cin >> G->vexs[i];  
    }  
    for (int i = 0; i < G->numVertex; i++)  
    {  
        for (int j = 0; j < G->numVertex; j++)  
        {  
            G->arc[i][j] = INT_MAX; //����Ȩֵ��ʼ��Ϊ�������ʾ���㲻����  
        }  
    }  
    cout << "������ÿ���ߵ������ţ��յ���ţ��ͱߵ�Ȩֵ��";  
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
    cout << "DFS���ʶ���˳��:   ";  
    DFSTraverse(G);  
    cout << endl;  
    cout << "BFS���ʶ���˳��:   ";  
    BFSTraverse(G);  
    cout << endl;  
    return 0;    
}  
 
