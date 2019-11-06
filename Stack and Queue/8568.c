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
            @Time: 2019/10/4 13:11
            @Project_NAME：Data_structure_experiment
            @FileName: 8568.c
            @IDE: CLion
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct data_queue {
    int data;
    struct data_queue *next;
} data_queue, *p_data_queue;
typedef struct local {
    p_data_queue front;
    p_data_queue rear;
} local, *p_local;

void init_queue(p_local p) {
    p->front = p->rear = (p_data_queue) malloc(sizeof(data_queue));
    p->front->next = NULL;
}

void inserted_data(p_local p, int data) {
    p_data_queue s;
    s = (p_data_queue) malloc(sizeof(struct data_queue));
    s->data = data;
    s->next = NULL;
    p->rear->next = s;
    p->rear = s;
}

void show_queue(p_local p) {
    p->front = p->front->next;
    printf("%d ", p->front->data);
}

int main() {
    int init_data = 1;
    int rows, print_row = 1, now_row = 1;
    scanf_s("%d", &rows);
    print_row = 1;
    struct local p, temp_p;
    temp_p = p;
    init_queue(&p);
    inserted_data(&p, init_data);
    show_queue(&p);
    printf("\n");
    inserted_data(&p, init_data);
    inserted_data(&p, init_data);
    printf("1 1");
    printf("\n");
    while (print_row <= rows) {
        while (1) {
            inserted_data(&p, (p.front->data) + (p.front->next->data));
            show_queue(&p);
            p.front = p.front->next;
            if (p.front->next->data == 1) {
                break;
            }
        }
        print_row++;
        printf("%d", p.front->data);
        printf("\n");
    }
}
