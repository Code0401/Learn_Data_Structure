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
            @Time: 2019/12/10 9:51
            @Project_NAME��Learn_Data_Structure
            @FileName: parking_management.cpp
            @IDE: CLion
*/
#include "parking_management.h"

using namespace std;

void enter_parking_lot()
{
    int number_plate;
    enter_park:
    system("cls");
    cout << "�����복�ƺ�:" << endl;
    cin >> number_plate;
    if (car_park.size() < 10)
    {
        car_park.push(number_plate);
        car_start_time[number_plate] = time((time_t *) nullptr);
        cout << "���ɹ�!" << endl;
        cout << "�Ƿ������Ҫͣ��" << endl;
        if (judge_to_do_what())
        {
            goto enter_park;
        } else
        {
            return;
        }

    } else
    {
        cout << "��������~" << endl;
        cout << "�Ƿ����ȴ�?" << endl;
        if (judge_to_do_what())
        {
            wait_to_park.push(number_plate);
        } else
        {
            return;
        }
    }
}

void enter_queue(int number_plate) //�������
{
    wait_to_park.push(number_plate);
    cout << "�����Ŷ�~" << endl;
}

void print_number_of_vehicles() //��ӡ���г�����
{
    cout << "���г���:" << car_park.size() << "��" << endl;
}

void outbound()
{
    int number_plate;
    cout << "��������⳵�ƺ�:" << endl;
    cin >> number_plate;
    for (int i = car_park.size(); i > 0; i--)
    {
        if (car_park.top() == number_plate)
        {
            cout << "ͣ��ʱ��:" << time((time_t *) nullptr) - car_start_time[number_plate] << "S" << endl;
            car_park.pop();
            if (!wait_to_park.empty())
            {
                car_park.push(wait_to_park.front());
                cout << "������:" << wait_to_park.front() << "�����" << endl;
                wait_to_park.pop();
            }
            break;
        } else
        {
            make_way.push(car_park.top());
            car_park.pop();
        }
        if (i == 0)
        {
            cout << "û�ҵ������ǲ���Ϊ����~" << endl;
        }
    }
    for (int i = 0; i < make_way.size(); i++)
    {
        car_park.push(make_way.top());
        make_way.pop();
    }
}

void calculate_park_time()
{
    int number_plate;
    cout << "�����복�ƺ�:" << endl;
    cin >> number_plate;
    cout << "ͣ��ʱ��:" << time((time_t *) nullptr) - car_start_time[number_plate] << "S" << endl;

}

int main()
{
    while (true)
    {
        welcome_to_parking_management();
        cout << "������������:";
        char to_do_what;
        cin >> to_do_what;
        system("cls");

        switch (to_do_what)
        {
            case '1':
                enter_parking_lot();
                break;
            case '2':
                print_number_of_vehicles();
                break;
            case '3':
                cout << "���п�λ:" << 10 - car_park.size() << "��" << endl;
                break;
            case '4':
                calculate_park_time();
                break;
            case '5':
                outbound();
                break;
            case '0':
                return 0;
            default:
                break;
        }
    }
}