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
            @Time: 2019/9/25 21:41
            @Project_NAME：Data_structure_experiment
            @FileName: 8563.c
            @IDE: CLion
*/
#define MAXSIZE 20

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int top;
    int data[MAXSIZE];
    int bottom;
} *p_stack, stack;

void initstack(p_stack s) {
    s->top = s->bottom = 0;
}

void push(p_stack s, int data) {
    s->data[s->top++] = data;
}

void show_stack(p_stack s) {
    int temp;

    while (1) {
        if (s->top == 0) { break; }
        else {
            temp = s->data[--s->top];
            printf("%d ", temp);
        }
    }

}

int main() {
    stack s;
    initstack(&s);
    while (1) {
        int insert_data;
        scanf_s("%d", &insert_data);
        if (insert_data == 0) {
            break;
        } else {
            push(&s, insert_data);
        }

    }
    show_stack(&s);
}