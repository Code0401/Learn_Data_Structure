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
            ���汣��       ����BUG
            
            @Author: Tao
            @Time: 2019/11/19 14:42
            @Project_NAME��Learn_Data_Structure
            @FileName: Linkedlist.c
            @IDE: CLion
*/
#include <iostream>

using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} node, *p_node;

//LinkList Create(void) //ͷ�巨
//{
//    LinkList head;
//    ElemType d;
//    LNode *s;
//    head=(LinkList)malloc (sizeof(LNode)); //head�ڵ�
//    head->next=NULL;   //��ʼ��Ϊ������
//    //head->data=0;
//    puts ("����������Ԫ��......");
//    d=getchar();
//    while (d!='\n')
//    {
//        s=(LinkList)malloc (sizeof(LNode)); //Ϊ�½ڵ�����ڴ�ռ�
//        s->data=d;
//        s->next=head->next;
//        head->next=s;
//        d=getchar();
//    }
//    return head;
//}

void create_link_list(p_node &head) //β�彨��������
{
    int temp_data;
    p_node tail, current;
    head = new node;
    head->data = -1;
    tail = head;
    while (cin >> temp_data)
    {
        current = new node;
        current->data = temp_data;
        tail->next = current;
        tail = tail->next;
    }
    cin.clear();
    tail->next = nullptr;
}

void show_linked_list(p_node head) //��ӡ������
{
    if (head->data == -1)
    {
        head = head->next;
    }
    while (head)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

void conut_linked_list_length(p_node &head) //����ڵ�����
{
    head = head->next;
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    cout << "������Ϊ��" << count;
}

void reverse_link_list(p_node head) //��ת����
{
    p_node prev = head, current = prev->next, temp;
    while (current)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    head->next = nullptr;
    show_linked_list(prev);
}

void x_to_last(p_node head) //��ӡ������x��
{
    int number = 2;
    cin >> number;
    p_node first_node = head->next;
    p_node forward_ptr = first_node, ptr = first_node;
    int count = 1;
    while (true)
    {
        count++;
        forward_ptr = forward_ptr->next;
        if (count == number)
        {
            break;
        }
    }
    while (forward_ptr->next != nullptr)
    {
        forward_ptr = forward_ptr->next;
        ptr = ptr->next;
    }
    cout << ptr->data << endl;
}

int main()
{
    p_node linked_list_head;
    create_link_list(linked_list_head);
//    show_linked_list(linked_list_head); //��ӡ����
//    conut_linked_list_length(linked_list_head); //����
//    reverse_link_list(linked_list_head); //����
//    x_to_last(linked_list_head); //��ӡ������x��
}