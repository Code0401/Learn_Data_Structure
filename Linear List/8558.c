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
            @Time: 2019/9/22 10:26
            @Project_NAME：Data_structure_experiment
            @FileName: 8558.c
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

void separation(Lnode *head) {
    head = head->next;
    Lnode *even, *odd_number, *even_temp, *odd_number_temp;
    even = even_temp = (Lnode *) malloc(sizeof(Lnode));
    odd_number = odd_number_temp = (Lnode *) malloc(sizeof(Lnode));
    while (head) {
        if (head->data % 2 == 0) {
            even_temp->next = head;
            even_temp = even_temp->next;
        } else if (head->data % 2 != 0) {
            odd_number_temp->next = head;
            odd_number_temp = odd_number_temp->next;
        }
        head = head->next;
    }
    if (even_temp->next) {
        even->next = NULL;
    }
    if (odd_number->next) {
        odd_number->next = NULL;
    }
    even->next = NULL;
    odd_number->next = NULL;
    show_link_list(even);
    show_link_list(odd_number);
}

void creat_link_list() {
    Lnode *prev, *current, *head, *to_inserted;
    head = prev = current = (Lnode *) malloc(sizeof(Lnode));
    while (1) {
        to_inserted = (Lnode *) malloc(sizeof(Lnode));
        scanf_s("%d", &to_inserted->data);
        if (to_inserted->data == 0) {
            to_inserted->data = NULL;
            break;
        }
        current->next = to_inserted;
        current = to_inserted;
    }
    current->next = NULL;
    separation(head);
}

int main() {
    creat_link_list();
}