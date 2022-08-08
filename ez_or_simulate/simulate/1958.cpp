#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
using namespace std;
/*
有4根柱子的汉诺塔，有n个盘，求移动次数
定义只有三根柱子时有n个盘的话移动次数是dn，然后dn=dn−1∗2+1
*/
int n = 12, d[13], f[13];
int main()
{
    for (int i = 1;i <= n;i++)
        d[i] = d[i - 1] * 2 + 1;//初始化
    f[1] = 1;
    printf("1\n");
    for (int i = 2;i <= n;i++)
    {
        f[i] = 2147483647;
        for (int j = 1;j < i;j++)
            f[i] = min(f[i], f[j] * 2 + d[i - j]);
        //递推求最优解
        printf("%d\n", f[i]);//输出
    }
}
