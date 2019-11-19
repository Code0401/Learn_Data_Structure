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
            @Time: 2019/11/7 19:24
            @Project_NAME：Learn_Data_Structure
            @FileName: 7076.c
            @IDE: CLion
*/
#include <iostream>

using namespace std;
typedef struct tree_node {
    char data;
    struct tree_node *lchild, *rchild;

} *p_tree,tree_nodee;

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

int count_tree_hight(p_tree &root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->lchild == nullptr && root->rchild == nullptr) {
        return 1;
    }
    return count_tree_hight(root->lchild) + count_tree_hight(root->rchild);
}

int main() {
    p_tree root;
    create_bintary_tree(root);
    auto result = count_tree_hight(root);
    cout << result;
}