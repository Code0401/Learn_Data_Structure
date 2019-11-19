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
            @Time: 2019/11/7 19:56
            @Project_NAME：Learn_Data_Structure
            @FileName: 7075.c
            @IDE: CLion
*/
#include <iostream>

using namespace std;
typedef struct tree_node {
    char data;
    struct tree_node *lchild, *rchild;

} *p_tree, tree_nodee;

void create_bintary_tree(p_tree &root) {
    char user_data;
    cin >> user_data;
    if (user_data != '@') {
        root = new tree_node;
        root->data = user_data;
        create_bintary_tree(root->lchild);
        create_bintary_tree(root->rchild);
    } else {
        root = nullptr;
    }
}

void post_order_traversal(p_tree &root) {
    if (root != nullptr) {
        post_order_traversal(root->lchild);
        post_order_traversal(root->rchild);
        cout << root->data;
    }
}


int main() {
    p_tree root;
    create_bintary_tree(root);
    post_order_traversal(root);
}