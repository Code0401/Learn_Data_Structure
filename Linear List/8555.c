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
            @Time: 2019/9/20 16:10
            @Project_NAME：Data_structure_experiment
            @FileName: 8555.c
            @IDE: CLion
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Lnode;

void show_link_list(Lnode *head) {
    head = head->next;
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}


void creat_link_list() {
    Lnode *work, *current, *head;
    head = work = (Lnode *) malloc(sizeof(Lnode));
    while (1) {
        current = (Lnode *) malloc(sizeof(Lnode));
        scanf_s("%d", &current->data);
        if (current->data == 0) {
            current->data = (int) NULL;
            break;
        }
        if (work != NULL) {
            while (work->data < current->data) {
                work = work->next;
            }
        }
        work->next = current;
        work = current;
    }
    show_link_list(head);
}

int main() {
    creat_link_list();
}
