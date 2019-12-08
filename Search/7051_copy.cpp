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
            @Time: 2019/12/8 19:31
            @Project_NAME：Learn_Data_Structure
            @FileName: 7051_copy.cpp
            @IDE: CLion
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define ElemType int
using namespace std;

typedef struct
{
    ElemType *data; //定义关键字为整型
    int count;  // 当前哈希表中的关键字个数
    int length; // 当前哈希表的容量
}HashTable;
HashTable H;

int p; // 构造hash函数mod值
ElemType Hash(ElemType key) // hash函数
{
    return key%p;
}
int Collision(int p, int c) //冲突处理函数
{//以线性探测再散列作为冲突处理方式
    // 冲突地址p， 增量地址c
    return (p+c)%H.length;  //重新找到的哈希地址
}

//void CreateHashTable()
int SearchHash(HashTable H, ElemType key, int &p, int &c)
{//查找关键字key在哈希表中的位置，如果查找成功则返回SUCCESS 1
    //用p返回关键字在哈希表中的位置。否则返回UNSUCCESS 0
    //用p返回关键字要插入的位置,c为处理冲突的次数
    int q;
    p=q=Hash(key);//取得关键字的哈希地址
    while(H.data[p]!=0&&H.data[p]!=key)
        p=Collision(q,++c);//若该存储位置上已有关键字并且关键字值与key不相等
    //则进行冲突处理
    if(H.data[p]==key)
        return 1;
    else
        return 0;
}

int InsertHash(HashTable &H, ElemType key)
{//若哈希表H中无关键字key则插入之
    int c = 0, p;
    if(SearchHash(H,key,p,c))   // 已经存在key
        return -1;

    if(c<=H.length)
    {
        //printf("哈希地址为%d \n",p);
        H.data[p]=key;
        H.count++;
        //printf("冲突次数为%d \n",c);
        return 1;
    }
    else
    {
        printf("冲突次数过多，请定义合适的哈希函数！\n");
        return -1;
    }
}


int main()
{
    int i;
    ElemType key;
    p=13;
    H.length = 15;
    H.data = (ElemType *)malloc(H.length*sizeof(ElemType));  // 申请空间
    for(i=0; i<H.length; i++)  // 初始化hash表
    {
        H.data[i] = 0;
    }
    //cout<<"逐个输入创建hash表:"<<endl;
    for(i=0; i<13; i++)  // 逐个输入创建hash表
    {
        cin>>key;
        InsertHash(H,key);
    }

    // 输出hash表
    for(i=0; i<15; i++)
    {
        //cout<<"第"<<i+1<<"个data：";
        cout<<i<<"  ";
    }
    cout<<"\n";
    for(i=0; i<15; i++)
    {
        cout<<H.data[i]<<"  ";
    }

    return 0;
}
