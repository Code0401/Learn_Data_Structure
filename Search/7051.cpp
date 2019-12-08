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
            @Time: 2019/12/2 15:54
            @Project_NAME：Learn_Data_Structure
            @FileName: 7081.c
            @IDE: CLion
*/
#include <iostream>
#include <cmath>

using namespace std;
typedef struct Hash_Table_Node
{
    int data;
    int flag;

} Hash_Table;

void init_hash_table(Hash_Table new_hash_table[])
{
    for (int i = 0; i < 20; i++)
    {
        new_hash_table[i].flag = 0;
    }
}

bool judge_prime(int data)
{
    for (int i = 2; i <= sqrt(data); i++)
    {
        if (data % i == 0)
        {
            return true;
        } else
        {
            return false;
        }
    }
}

int find_seed(int length)
{
    int i;
    for (i = length; i >= 0; i--)
    {
        if (judge_prime(i))
        {
            return i;
        }
    }
    return length - 1;

}

int find_hash_key(int data, int seed, Hash_Table hash_table[])
{
    int initial_position = data % seed;;
    int increment = 1;
    if (hash_table[initial_position].flag == 0)
    {
        return initial_position;
    } else
    {
        while (hash_table[initial_position].flag == 1)
        {
            initial_position = (initial_position + increment) % seed;
            increment++;
        }
        return initial_position;
    }
}

void print_hash_table(Hash_Table hash_table[], int i)
{
    if (hash_table[i].flag)
    {
        cout << hash_table[i].data << " ";
    }
}

int main()
{
    auto new_hash_table = new Hash_Table[20];
    init_hash_table(new_hash_table);
    int length, position;
    cin >> length;
    int data = -1;
    auto seed = find_seed(length);
    for (int i = 0; i < length; i++)
    {
        cin >> data;
        if (data == 0)
        {
            break;
        }
        position = find_hash_key(data, seed, new_hash_table);
        new_hash_table[position].flag = 1;
        new_hash_table[position].data = data;
    }
    for (int i = 0; i <= length; i++)
    {
        print_hash_table(new_hash_table, i);
    }
    return 0;
}