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
            @Time: 2019/11/7 20:11
            @Project_NAME：Learn_Data_Structure
            @FileName: 7079.c
            @IDE: CLion
*/
#include <iostream>
#include <stack>

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

void in_middle_order(p_tree &root) {
    stack<p_tree> temp;
    p_tree work = root;
    while (work != nullptr || !temp.empty()) {
        while (work != nullptr) {
            temp.push(work);
            work = work->lchild;
        }
        if (!temp.empty()) {
            work = temp.top();
            cout << work->data;
            temp.pop();
            work = work->rchild;
        }
    }
}

int main() {
    p_tree root;
    create_bintary_tree(root);
    in_middle_order(root);
}