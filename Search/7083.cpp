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
            @Time: 2019/12/1 10:40
            @Project_NAME：Learn_Data_Structure
            @FileName: 7083.c
            @IDE: CLion
*/
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int data[100];
    int count = 0;
    int temp, i = 1;
    while (true)
    {
        cin >> temp;
        if (temp == 0)
        {
            break;
        }
        data[i] = temp;
        i++;
    }
    int target;
    cin >> target;
    sort(data + 1, data + i);
    int low = 1, high = i - 1;
    while (low <= high)
    {
        count++;
        int mid = (low + high) / 2;
        if (data[mid] < target)
        {
            low = mid + 1;
        } else if (data[mid] > target)
        {
            high = mid - 1;
        } else
        {
            cout << data[mid] << " ";
            cout << count;
            return 1;
        }
    }
}