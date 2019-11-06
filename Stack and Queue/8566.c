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
            @Time: 2019/10/2 19:13
            @Project_NAME：Data_structure_experiment
            @FileName: 8566.c
            @IDE: CLion
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct data_stack {
    int data;
    struct data_stack *next;
} *p_data_stack;
typedef struct point_stack {
    p_data_stack top;
    p_data_stack bottom;
} *p_point_stack;

p_point_stack push(p_point_stack p, int data);

void division_num(p_point_stack p, int Num, int decimal);

void init_stack(p_point_stack p) {
    p->top = p->bottom = (p_data_stack) malloc(sizeof(point_stack));
    p->top->next = NULL;
};

void show_stack(p_point_stack p, int num, int decimal) {
    printf("%d(10)=", num);
    while (1) {
        if (p->top->next != NULL) {
            p_point_stack temp;
            temp = (p_point_stack) p->top;
            printf("%d", p->top->data);
            p->top = (p_data_stack) p->top->next;
            free(temp);
        } else {
            break;
        }
    }
    printf("(%d)", decimal);
}

void division_num(p_point_stack p, int Num, int decimal) {
    int remainder, recoder_num = Num, recoder_decimal = decimal;
    while (1) {
        if (Num <= 0) {
            break;
        } else {
            remainder = Num % decimal;
            p = push(p, remainder);
            Num /= decimal;
        }
    }
    show_stack(p, recoder_num, recoder_decimal);
}

p_point_stack push(p_point_stack p, int data) {
    p_data_stack temp;
    temp = (p_data_stack) malloc(sizeof(data_stack));
    temp->data = data;
    temp->next = (struct data_stack *) p->top;
    p->top = temp;
    return p;
}

int main() {
    int Num, Decimal;
    scanf_s("%d %d", &Num, &Decimal);
    point_stack p;
    init_stack(&p);
    division_num(&p, Num, Decimal);
}