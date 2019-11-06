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
            @Time: 2019/11/3 15:26
            @Project_NAME：Data_structure_experiment
            @FileName: 7079.c
            @IDE: CLion
*/
#include <stdio.h>
#include <stdlib.h>

typrdef struct tree {
    char data;
    struct tree *right_child, *left_child;
} tree, *p_tree;

typedef struct stack_node {
    p_tree tree_node;
    struct stack_node *next;
} stack_node, *p_stack;

void initialize_stack(p_stack pStack) {
    pStack->tree_node = NULL;
    pStack->next = NULL;
}

void push_stack(p_stack pStack, p_tree data) {
    p_stack node;
    node = (p_stack) malloc(sizeof(stack_node));
    node->tree_node = data;
    node->next = pStack;
    pStack = node;
}

void InOrderTraverse(p_tree root){
    p_stack pStack;
    initialize_stack(&pStack);
    push_stack(pStack,root);
    while(pStack!=NULL){
        while
    }
}

void creat_bintary_tree(p_tree root) {
    char user_data;
    scanf("%c", &user_data);
    if (user_data != '@') {
        root = (p_tree)
        malloc(sizeof(tree));
        (*root)->data = user_data;
        creat_bintary_tree((&(*root)->left_child));
        creat_bintary_tree((&(*root)->right_child));
    } else {
        (*root)->data = NULL;
    }
}

int main() {
    p_tree tree_root = NULL;
    creat_bintary_tree(tree_root);

}