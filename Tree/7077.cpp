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
            @Time: 2019/11/6 11:12
            @Project_NAME：Learn_C
            @FileName: 7077.c
            @IDE: CLion
*/
#include <iostream>
#include <queue>

using namespace std;
typedef struct tree_node {
    char data;
    struct tree_node *lchild;
    struct tree_node *rchild;
} tree_node, *p_tree;

void create_bintary_tree(p_tree &root) {
    char data;
    cin >> data;
    if (data != '@') {
        root = new tree_node;
        root->data = data;
        create_bintary_tree(root->lchild);
        create_bintary_tree(root->rchild);
    } else {
        root = nullptr;
    }

}

void FloorPrint_QUEUE(p_tree root) {
    queue<p_tree> work;
    if (root != nullptr) {
        work.push(root);
    }
    while (!work.empty()) {
        cout << work.front()->data;
        if (work.front()->lchild != nullptr) {
            work.push(work.front()->lchild);
        }
        if (work.front()->rchild != nullptr) {
            work.push(work.front()->rchild);
        }
        work.pop();
    }
}

int main() {
    p_tree root;
    create_bintary_tree(root);
    FloorPrint_QUEUE(root);

}