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
            ���汣��       ����BUG
            
            @Author: Tao
            @Time: 2019/10/21 20:18
            @Project_NAME��Data_structure_experiment
            @FileName: 7080.c
            @IDE: CLion
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    char data;
    struct tree *left_child, *right_child;
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

int binarytree_getleafnum(p_tree work) {
    int num;
    if (work == NULL) {
        return 0;
    }
    if (work->left_child == NULL) {
        if (work->right_child != NULL) {
            binarytree_getleafnum(work->right_child);
            return 2;
        }
        return 1;
    }
    return binarytree_getleafnum(work->left_child) + binarytree_getleafnum(work->right_child);
}

void print_leaves(p_tree bintary_tree) {
    if (bintary_tree == NULL) {
        return;
    }
    if (bintary_tree->left_child != NULL) {
        print_leaves(bintary_tree->right_child);
        print_leaves(bintary_tree->left_child);
    } else {
        printf("%c", bintary_tree->data);
        if (bintary_tree->right_child != NULL) {
            print_leaves(bintary_tree->right_child);
        }
    }
}

void bintary_tree(p_tree work) {
    if (work == NULL) {
        return;
    }
    printf("%c", work->data);
    bintary_tree(work->left_child);
    bintary_tree(work->right_child);
}



int main() {
    int num = 0;
    p_tree binarytree = NULL;
    create_tree(&binarytree);
//    print_leaves(binarytree);
//    bintary_tree(binarytree);
    num = binarytree_getleafnum(binarytree);
    printf("%d", num);
}