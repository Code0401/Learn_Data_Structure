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
            @Time: 2019/11/3 16:54
            @Project_NAME：Learn_C
            @FileName: 7078.c
            @IDE: CLion
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    char data;
    struct tree *left_child, *right_child;
    int LTag, RTag;
} tree, *p_tree;

void create_tree(p_tree *binarytree) {
    char user_data;
    scanf("%c", &user_data);
    if (user_data != '@') {
        *binarytree = (p_tree) malloc(sizeof(tree));
        (*binarytree)->data = user_data;
        create_tree(&(*binarytree)->left_child);
        create_tree(&(*binarytree)->right_child);
    } else {
        *binarytree = NULL;
    }
}

p_tree pre = NULL;

void InThreading(p_tree work)  //中序遍历的递归算法 将二叉树线索化
{
    if (work) {
        InThreading(work->left_child);
        if (work->left_child == NULL) {
            work->LTag = 1;
            work->left_child = pre;
        } else {
            work->LTag = 0;
        }
        if (pre == NULL) {
            pre->RTag = 1;
            pre->right_child = work;
        } else {
            pre->RTag = 0;
        }
        pre = work;
        InThreading(work->right_child);
    }

}


p_tree InorderThreading(p_tree head, p_tree bintarytree) //加入头节点
{
    head = (p_tree) malloc(sizeof(tree));
    head->LTag = 0;
    head->RTag = 1;
    head->right_child = head;
    if (bintarytree == NULL) {
        head->left_child = head;
    } else {
        head->left_child = bintarytree;
        pre = head;
        InThreading(bintarytree);
        pre->right_child = head;
        pre->RTag = 1;
        head->right_child = pre;
    }
    return head;
}

void print_InorderTraverse(p_tree bintarytree)  //遍历打印
{
    p_tree work;
    work = bintarytree->left_child;
    while (work != bintarytree) {
        while (work->LTag == 0) {
            work = work->left_child;
        }
        printf("%c", work->data);
        while (work->RTag == 1 && work->right_child != bintarytree) {
            work = work->right_child;
            printf("%c", work->data);
        }
        work = work->right_child;
    }
}

int main() {
    p_tree bintarytree;
    p_tree head = NULL;
    create_tree(&bintarytree);
    head = InorderThreading(head, bintarytree);
    print_InorderTraverse(head);
}