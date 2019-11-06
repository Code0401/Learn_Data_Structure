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
            @Time: 2019/9/23 21:26
            @Project_NAME：Data_structure_experiment
            @FileName: 8560.c
            @IDE: CLion
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int power;
    int coefficient;
    struct node *next;
} Lnode;

void show_link_list(Lnode *head) {
    head = head->next;
    while (head) {
        if (head->coefficient != 0) {
            printf("%d*x^%d", head->coefficient, head->power);
            if (head->next != NULL) { printf(" "); }
            head = head->next;
        } else {
            head = head->next;
        }

    }
}

void add_link_list(Lnode *head0, Lnode *head1) {
    Lnode *result, *work0 = head0, *work1 = head1, *temp_result;
    result = (Lnode *) malloc(sizeof(Lnode));
    result->next = NULL;
    temp_result = result;
    while (work0 != NULL && work1 != NULL) {
        if (work0->power > work1->power) {
            temp_result->next = work1;
            temp_result = temp_result->next;
            work1 = work1->next;
        } else if (work0->power < work1->power) {
            temp_result->next = work0;
            temp_result = temp_result->next;
            work0 = work0->next;
        } else {
            work0->coefficient = work0->coefficient + work1->coefficient;
            temp_result->next = work0;
            temp_result = temp_result->next;
            work1 = work1->next;
            work0 = work0->next;
        }
    }

    if (work1) {
        temp_result->next = work1;
        temp_result->next->next = NULL;
    } else if (work0) {
        temp_result->next = work0;
        temp_result->next->next = NULL;
    } else {
        temp_result->next = NULL;
    }
    show_link_list(result);
}

Lnode *creat_link_list() {
    Lnode *head, *tail, *current;
    head = tail = (Lnode *) malloc(sizeof(Lnode));
    int length;
    scanf("%d", &length);
    while (length) {
        current = (Lnode *) malloc(sizeof(Lnode));
        scanf("%d,%d", &current->coefficient, &current->power);
        current->next = NULL;
        tail->next = current;
        tail = current;
        length--;
    }
    return head;
}


int main() {
    Lnode *head0, *head1;
    head0 = creat_link_list();
    head1 = creat_link_list();
    add_link_list(head0->next, head1->next);
}