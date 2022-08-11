#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
/*
SIN 号在 0 ~10^6 范围内，在每个组里找到一个最小的正整数m，是的当前组内的所有数对模m均不同余
*/

bool flag[1000000];//判断余数为数组下标是否已经存在
int fn[301];//保存学号

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin>>m;
        for (int i = 0; i < m;i++)
        {
            cin>>fn[i];
        }
        for (int i = 1;i < 1000000;i++)
        {
            bool index = true;
            memset(flag, 0, i);//只能存在i个不同的余数
            for (int j = 0;j < m;j++)
            {
                if (flag[fn[j] % i])
                {
                    index = false;//已经发现相同的余数,跳出循环i加1后再遍历
                    break;
                }
                flag[fn[j] % i] = true;//该余数存在
            }
            if (index)
            {//余数各不相同,输出i             
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
