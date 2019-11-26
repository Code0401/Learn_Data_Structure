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
            @Time: 2019/11/26 18:37
            @Project_NAME：Learn_Data_Structure
            @FileName: 7043.c
            @IDE: CLion
*/
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
typedef struct edge_node
{
    int adjvex;
    struct edge_node *next;
} edge_node;
typedef struct vertex_node
{
    int data;
    edge_node *first_edge;
} vertex_node;
typedef struct Graph_adj_list
{
    vertex_node adj_list[20];
    int vertexes_num, edges_num;
} Graph_adj_list;

void create_graph(Graph_adj_list *g)
{
    int m = 0, n = 0;
    edge_node *temp_edge_node;
    scanf("%d %d", &g->vertexes_num, &g->edges_num);
    for (int i = 1; i <= g->vertexes_num; i++)
    {
        scanf("%d", &g->adj_list[i].data);
        g->adj_list[i].first_edge = nullptr;
    }
    for (int i = 1; i <= g->edges_num; i++)
    {
        scanf("%d %d", &m, &n);
        temp_edge_node = new edge_node;
        temp_edge_node->adjvex = n;
        temp_edge_node->next = g->adj_list[m].first_edge;
        g->adj_list[m].first_edge = temp_edge_node;

        temp_edge_node = new edge_node;
        temp_edge_node->adjvex = m;
        temp_edge_node->next = g->adj_list[n].first_edge;
        g->adj_list[n].first_edge = temp_edge_node;
    }
}

void bfs(Graph_adj_list *g)
{
    queue<int> preparatory;
    edge_node *work;
    bool traversal_status[20] = {false};
    for (int i = 1; i <= g->vertexes_num; i++)
    {
        if (!traversal_status[i])
        {
            traversal_status[i] = true;
            cout << "v" << g->adj_list[i].data << " ";
            preparatory.push(i);
            while (!preparatory.empty())
            {
                i = preparatory.front();
                preparatory.pop();
                work = g->adj_list[i].first_edge;
                while (work)
                {
                    if (!traversal_status[work->adjvex])
                    {
                        traversal_status[work->adjvex] = true;
                        cout << "v" << g->adj_list[work->adjvex].data << " ";
                        preparatory.push(work->adjvex);
                    }
                    work = work->next;
                }
            }
        }
    }
}

int main()
{
    auto new_graph = new Graph_adj_list;
    create_graph(new_graph);
    cout << endl;
    bfs(new_graph);
}