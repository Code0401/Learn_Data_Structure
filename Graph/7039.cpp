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
            @Time: 2019/11/26 9:12
            @Project_NAME：Learn_Data_Structure
            @FileName: 7039.c
            @IDE: CLion
 */
#include <iostream>
#include <cstdio>

using namespace std;

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *next;
} ArcNode;

typedef struct VNode
{
    int data;
    ArcNode *firstarcnode;
} VNode, AdjList[20];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

void create_graph(ALGraph *G)
{
    scanf("%d %d", &G->vexnum, &G->arcnum);
    for (int i = 1; i <= G->vexnum; i++)
    {
        cin >> G->vertices[i].data;
        G->vertices[i].firstarcnode = nullptr;
    }

}

int main()
{
    auto *new_graph = new ALGraph;
    create_graph(new_graph);
}