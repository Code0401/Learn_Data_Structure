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
            @Time: 2019/12/4 9:37
            @Project_NAME：Learn_Data_Structure
            @FileName: 7081.c
            @IDE: CLion
*/
#include <iostream>

using namespace std;

typedef struct bintary_tree_node
{
    int data;
    struct bintary_tree_node *left_child, *right_child;
} bintary_tree_node, *pointer_to_binary_tree_node;

bintary_tree_node *search_BST(bintary_tree_node *BST, bintary_tree_node *forward, int target)
{
    if (!BST)
    {
        return forward;
    } else if (target == BST->data)
    {
        return BST;
    } else if (target > BST->data)
    {
        search_BST(BST->right_child, BST, target);
    } else if (target < BST->data)
    {
        search_BST(BST->left_child, BST, target);
    }

}

bintary_tree_node *insert_BST(bintary_tree_node **BST, int data)
{
    bintary_tree_node *to_be_inserted, *new_node;
    new_node = new bintary_tree_node;
    new_node->data = data;
    new_node->left_child = new_node->right_child = nullptr;
    to_be_inserted = search_BST(*BST, nullptr, data);
    if (!to_be_inserted)
    {
        *BST = new_node;
    } else if (data < new_node->data)
    {
        to_be_inserted->left_child = new_node;
    } else
    {
        to_be_inserted->right_child = new_node;
    }
}

int main()
{
    auto BST = new bintary_tree_node;
    int data = -1;
    while (data != 0)
    {
        cin >> data;
        insert_BST(&BST, data);
    }
    int search_target;
    cin >> search_target;
    cout << search_BST(BST, nullptr, search_target)->data;
}