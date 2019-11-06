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
            ·ð×æ±£ÓÓ       ÓÀÎÞBUG
            
            @Author: Tao
            @Time: 2019/10/2 20:29
            @Project_NAME£ºData_structure_experiment
            @FileName: 8569.c
            @IDE: CLion
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data[20];
    int front;
    int rear;
} queue;

void init_queue(queue *p) {
    p->front = p->rear = 0;
}

void inserted(queue *p, int data) {
    p->data[p->front] = data;
    p->front++;
}

void show_queue(queue *p) {
    while (p->front != p->rear) {
        printf("%d ", p->data[p->rear]);
        p->rear++;
    }
}

int main() {
    queue p;
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

