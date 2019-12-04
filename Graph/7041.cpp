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
            
            @Author: tao
            @Time: 2019/11/30 上午10:48
            @Project_NAME：Learn_Data_Structure
            @FileName: 7041.cpp
            @IDE: CLion
 */
#include <iostream>
#include <cstdio>
#include <stack>

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
int in_degree[20] = {0};

void count_in_degree(Graph_adj_list *G)
{
    edge_node *work;
    for (int i = 1; i <= G->vertexes_num; i++)
    {
        work = G->adj_list[i].first_edge;
        while (work)
        {
            in_degree[work->adjvex]++;
            work = work->next;
        }
    }
}

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
    }
}

void topological_sort(Graph_adj_list *g)
{
    stack<int> stack;
    int j;
    edge_node *work;
    auto count = 0;
    for (int i = 1; i <= g->vertexes_num; i++)
    {
        if (in_degree[i] == 0)
        {
            stack.push(i);
        }
    }
    while (!stack.empty())
    {
        auto stack_top_node = stack.top();
        stack.pop();
        cout << "v" << g->adj_list[stack_top_node].data << " ";
        count++;
        work = g->adj_list[stack_top_node].first_edge;
        while (work)
        {
            j = work->adjvex;
            --in_degree[j];
            if (in_degree[j] == 0)
            {
                stack.push(j);
            }
            work = work->next;
        }
    }
}

int main()
{
    auto new_graph = new Graph_adj_list;
    create_graph(new_graph);
    count_in_degree(new_graph);
    topological_sort(new_graph);
}