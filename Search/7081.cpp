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

bool search_BST(bintary_tree_node BST, pointer_to_binary_tree_node forward, int target,
                pointer_to_binary_tree_node &Parent)
{
    if (!BST)
    {
        Parent = forward;
        return true;
    } else if (target == BST->data)
    {
        Parent = BST;
        return false;
    } else if (target > BST->data)
    {
        search_BST(BST->right_child, BST, target, Parent);
    } else if (target < BST->data)
    {
        search_BST(BST->left_child, BST, target, Parent);
    }

}

bool insert_BST(bintary_tree_node &BST, int data)
{
    bintary_tree_node Parent;

    if (search_BST(BST, nullptr, data, Parent))
    {

    }
}

int main()
{
    auto BST = new bintary_tree_node;
    int data = -1;
    while (data != 0)
    {
        cin >> data;
        insert_BST(BST, data);
    }
    int search_target;
    cin >> search_target;
    cout << search_BST(BST, nullptr, search_target)->data;
}