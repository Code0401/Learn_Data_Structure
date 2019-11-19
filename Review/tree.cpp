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
            @Time: 2019/11/19 17:20
            @Project_NAME：Learn_Data_Structure
            @FileName: tree.c
            @IDE: CLion
*/
# include <bits/stdc++.h>

using namespace std;
typedef struct binarytree_node
{
    char data;
    binarytree_node *l_child;
    binarytree_node *r_child;
} binarytree_node, *p_binarytree_node;

void create_binarytree(p_binarytree_node &root) //建立二叉树
{
    char temp_data;
    cin >> temp_data;
    if (temp_data != '@')
    {
        root = new binarytree_node;
        root->data = temp_data;
        create_binarytree(root->l_child);
        create_binarytree(root->r_child);
    } else
    {
        root = nullptr;
    }

}

int count_binarytree_node(p_binarytree_node root) //统计节点个数
{
    if (root == nullptr)
    {
        return 0;
    }
    return count_binarytree_node(root->l_child) + count_binarytree_node(root->r_child) + 1;
}

int binarytree_deepth(p_binarytree_node &root) //求树深度
{
    if (root == nullptr)
    {
        return 0;
    }
    return max(binarytree_deepth(root->l_child), binarytree_deepth(root->r_child)) + 1;
}

void sequence_traversal(p_binarytree_node &root) //层序遍历
{
    queue<p_binarytree_node> sequence_traversal_queue;
    sequence_traversal_queue.push(root);
    p_binarytree_node current;
    while (!sequence_traversal_queue.empty())
    {
        current = sequence_traversal_queue.front();
        cout << current->data;
        sequence_traversal_queue.pop();
        if (current->l_child != nullptr)
        {
            sequence_traversal_queue.push(current->l_child);
        }
        if (current->r_child != nullptr)
        {
            sequence_traversal_queue.push(current->r_child);
        }
    }
}

p_binarytree_node mirror_tree(p_binarytree_node &root) //镜像
{
    if (root == nullptr)
    {
        return nullptr;
    }
    p_binarytree_node p_l_child = mirror_tree(root->l_child);
    p_binarytree_node p_r_child = mirror_tree(root->r_child);
    root->l_child = p_r_child;
    root->r_child = p_l_child;
    return root;
}

int main()
{
    p_binarytree_node root;
    create_binarytree(root); //创建二叉树
//    cout << count_binarytree_node(root); //统计节点个数
//    cout << binarytree_deepth(root); //求树深度
    sequence_traversal(root); //层序遍历
//    mirror_tree(root); //镜像
}