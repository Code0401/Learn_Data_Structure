/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            佛祖保佑       永无BUG
            
            @Author: Tao
            @Time: 2019/11/11 17:04
            @Project_NAME：Learn_Data_Structure
            @FileName: 7040.c
            @IDE: CLion
*/
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

typedef int VertexType;

typedef struct EdgeNode //边表节点
{
    int adjvex;
    struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode //顶点表节点
{
    VertexType data;
    EdgeNode *firstedge;
} VertexNode, AdjList[20];

typedef struct
{
    AdjList adjlist;
    int numVertexes, numEdges;
} GraphAdjList;

void createALGraph(GraphAdjList *G)
{
    int i = 0, j = 0, k, l;
    EdgeNode *temp;
    scanf("%d %d", &G->numVertexes, &G->numEdges);
    for (l = 1; l <= G->numVertexes; l++)
    {
        scanf("%d", &G->adjlist[l].data);
        G->adjlist[l].firstedge = nullptr;
    }
    for (k = 1; k <= G->numEdges; k++)
    {
        scanf("%d %d", &i, &j);
        temp = new EdgeNode;
        temp->adjvex = j;
        temp->next = G->adjlist[i].firstedge;
        G->adjlist[i].firstedge = temp;
//        temp = new EdgeNode;
//        temp->adjvex = i;
//        temp->next = G->adjlist[j].firstedge;
//        G->adjlist[j].firstedge = temp;
    }
}

void count_out_degree(GraphAdjList *G, int out_degree[])
{
    EdgeNode *work;
    int count = 0;
    for (int i = 1; i <= G->numVertexes; i++)
    {
        work = G->adjlist[i].firstedge;
        while (work)
        {
            count++;
            work = work->next;
        }
        out_degree[i] = count;
        count = 0;
    }
}

void count_in_degree(GraphAdjList *G, int in_degree[])
{
    EdgeNode *work;
    for (int i = 1; i <= G->numVertexes; i++)
    {
        work = G->adjlist[i].firstedge;
        while (work)
        {
            in_degree[work->adjvex]++;
            work = work->next;
        }
    }
}

int main()
{
    int out_degree[20] = {0};
    int in_degree[20] = {0};
    auto *Graph = new GraphAdjList;
    createALGraph(Graph);
    count_out_degree(Graph, out_degree);
    count_in_degree(Graph, in_degree);
    for (int i = 1; i <= Graph->numVertexes; i++)
    {
        cout << i << ":" << in_degree[i] << " " << out_degree[i] << " " << in_degree[i] + out_degree[i] << endl;
    }
}