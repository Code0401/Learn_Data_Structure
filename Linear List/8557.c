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
            @Time: 2019/9/20 20:48
            @Project_NAME：Data_structure_experiment
            @FileName: 8557.c
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




Lnode *creat_link_list() {
    Lnode *tail=NULL, *current, *head;
    head = current = tail = (Lnode *) malloc(sizeof(Lnode));
    while (1) {
        current = (Lnode *) malloc(sizeof(Lnode));
        scanf_s("%d", &current->data);
        if (current->data == 0) {
            current->data = (int) NULL;
            break;
        } else {
            tail->next = current;
            tail = current;
        }
    }
    current->next = NULL;
    return head;
}

int main() {
    Lnode *head_0, *head_1;
    head_0 = creat_link_list();
    head_1 = creat_link_list();
    add_link_list(head_0, head_1);
}