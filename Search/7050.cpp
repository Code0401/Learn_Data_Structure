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
            @Time: 2019/12/8 20:00
            @Project_NAME：Learn_Data_Structure
            @FileName: 7050.cpp
            @IDE: CLion
*/
#include <iostream>
#include <algorithm>

using namespace std;
struct Node
{
    int key;
    Node *next;
};
Node HashTable[13];
int a[13];

int InsertHT(int x, int w)
{
    int adr;
    Node *p;
    adr = x % w;
    p = &HashTable[adr];
    while (p->next)
    {
        if (p->next->key == x)
            return -1;
        p = p->next;
    }
    Node *s;
    s = new Node;
    s->key = x;
    s->next = p->next;
    p->next = s;
    return 1;
}

void CreateHT(int n, int m, int p)
{
    for (int i = 0; i < n; i++)
    {
        HashTable[i].key = i;
        HashTable[i].next = NULL;
    }
    for (int i = 0; i < m; i++)
        InsertHT(a[i], p);
}

void Display(int n, int m)
{
    int add[13], j, count;
    Node *q;
    for (int i = 0; i < 13; i++)
    {
        j = 0;
        count = 0;
        q = (&HashTable[i])->next;
        while (q != NULL)
        {
            add[j] = q->key;
            j++;
            count++;
            q = q->next;
        }
        sort(add, add + count);
        q = (&HashTable[i])->next;
        j = 0;
        while (q != NULL)
        {
            q->key = add[j];
            j++;
            q = q->next;
        }
    }
    cout << 0 << ":" << endl;
    for (int i = 1; i < 13; i++)
    {
        q = &HashTable[i];
        while (q->next != NULL)
        {
            cout << q->key << "";
            q = q->next;
        }
        cout << q->key << " " << endl;
    }
}

int main()
{
    for (int i = 0; i < 13; i++)
        cin >> a[i];
    CreateHT(13, 13, 13);
    Display(13, 13);
    return 0;
}