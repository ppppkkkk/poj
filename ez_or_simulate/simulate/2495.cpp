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
 8*8的棋盘被扣掉两个，问还能用2*1的瓷砖完全覆盖不？
就是把棋盘染色成国际象棋黑白相间的棋盘，如果两个格子同色则不可，否则可以。
if (((a + b) & 1) == ((c + d) & 1))同奇偶，不行
*/


int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        printf("Scenario #%d:\n", i + 1);
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (((a + b) & 1) == ((d + c) & 1))
            printf("0\n");
        else
            printf("1\n");
        printf("\n");
    }
    return 0;
}
