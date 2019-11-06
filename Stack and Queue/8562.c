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
            @Time: 2019/10/2 11:00
            @Project_NAME：Data_structure_experiment
            @FileName: 8562.c
            @IDE: CLion
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    int *next;
} stack, *p_stack;

typedef struct {
    p_stack top;
    p_stack bottom;
} stack_node;

void initstack(stack_node *s) {
    s->bottom = (p_stack) malloc(sizeof(stack));
    s->top = s->bottom;
    s->top->next = NULL;

}

void push(stack_node *s, int data) {
    p_stack ptr;
    ptr = (stack *) malloc(sizeof(stack));
    ptr->data = data;
    ptr->next = (int *) s->top;
    s->top = ptr;
}

void show_link_stack(stack_node *s) {
    while (s->top->next != NULL) {
        stack_node *p;
        p = (stack_node *) s->top;
        printf("%d ", s->top->data);
        s->top = (p_stack) s->top->next;
        free(p);
    }

}

int main() {
    int data;
    stack_node s;
    initstack(&s);
    while (1) {
        scanf_s("%d", &data);
        if (data == 0) {
            break;
        } else {
            push(&s, data);
        }
    }
    show_link_stack(&s);
}