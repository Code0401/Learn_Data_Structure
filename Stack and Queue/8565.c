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
            @Time: 2019/10/4 9:07
            @Project_NAME：Data_structure_experiment
            @FileName: 8565.c
            @IDE: CLion
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct data_queue {
    int data;
    struct data_queue *next;
}  data_queue,*p_data_queue;

typedef struct {
    p_data_queue front;
    p_data_queue rear;
} p_queue;

void init_queue(p_queue *p) {
    p->front = p->rear = (p_data_queue) malloc(sizeof(data_queue));
    p->front->next = NULL;
}

void inserted(p_queue *p, int data) {
    p_data_queue s;
    s = (p_data_queue) malloc(sizeof(data_queue));
    s->data = data;
    s->next = NULL;
    p->rear->next = (struct data_queue *) s;
    p->rear = s;
}

void show_queue(p_queue *p) {
    p->front = (p_data_queue) (p_queue *) p->front->next;
    while (p->front) {
        printf("%d ", p->front->data);
        p->front = (p_data_queue) p->front->next;
    }
}


int main() {
    p_queue p;
    init_queue(&p);
    while (1) {
        int insert_data;
        scanf_s("%d", &insert_data);
        if (insert_data == 0) {
            break;
        } else {
            inserted(&p, insert_data);
        }
    }
    show_queue(&p);
}