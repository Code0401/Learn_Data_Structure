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
            @Time: 2019/12/8 20:44
            @Project_NAME：Learn_Data_Structure
            @FileName: 8549.cpp
            @IDE: CLion
*/
#include <iostream>

using namespace std;
int data[20] = {0};

void swap_data(int a, int b)
{
    int temp;
    temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}

int partition(int low, int high)
{
    int pivotkey;
    pivotkey = data[low];
    while (low < high)
    {
        while (low < high && data[high] >= pivotkey)
        {
            high--;
        }
        swap_data(low, high);
        while (low < high && data[low] <= pivotkey)
        {
            low++;
        }
        swap_data(low, high);
    }
    return low;
}

void quick_sort(int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partition(low, high);
        quick_sort(low, pivot - 1);
        quick_sort(pivot + 1, high);
    }
}


int main()
{
    int temp;
    int i = -1;
    while (1)
    {
        cin >> temp;
        if (temp != 0)
        {
            data[++i] = temp;
        } else
        {
            break;
        }
    }
    quick_sort(0, i - 1);
    for (int j = 0; j < i; j++)
    {
        cout << data[j] << " ";
    };
}