//
// Created by Tao on 2019/12/10.
//

#ifndef LEARN_DATA_STRUCTURE_PARKING_MANAGEMENT_H
#define LEARN_DATA_STRUCTURE_PARKING_MANAGEMENT_H

#include <iostream>
#include <queue>
#include <stack>
#include<map>
#include <ctime>

using namespace std;
stack<int> car_park;
queue<int> wait_to_park;
stack<int> make_way;

map<int, time_t> car_start_time;

void welcome_to_parking_management()
{
    cout << "\n";
    cout << "                     ***Ω��ľ֮�����⣬������֮��ĺ*** " << endl;
    cout << "                    �x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x" << endl;
    cout << "                    ��                               |" << endl;
    cout << "                    ��        1.�������              |" << endl;
    cout << "                    ��        2.��ӡ���г�����         |" << endl;
    cout << "                    ��        3.��ӡͣ������λ         |" << endl;
    cout << "                    ��        4.���ҳ������ʱ��       |" << endl;
    cout << "                    ��        5.��������              |" << endl;
    cout << "                    ��        0.�˳�                 |" << endl;
    cout << "                    ��                               |" << endl;
    cout << "                    ����������������������������������������������������������������" << endl;

}

bool judge_to_do_what()
{
    char user_choice;
    cin >> user_choice;
    if (user_choice == 'y' || user_choice == 'Y')
    {
        return true;
    } else
    {
        return false;
    }
}

//void enter_queue();

void enter_parking_lot();

void print_number_of_vehicles();

void outbound();

void calculate_park_time();

#endif //LEARN_DATA_STRUCTURE_PARKING_MANAGEMENT_H
