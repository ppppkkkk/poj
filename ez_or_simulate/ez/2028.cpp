#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
给定N，Q，N代表人数，Q代表最少需要参加的人数
，接下来N行表示每个人方便的日期。选出一个日期尽可能满足要求的日期

*/



int main()
{
    int num[105];
    int n, m;
    int max_int, index;
    while (scanf("%d%d", &n, &m), n)
    {
        memset(num, 0, sizeof(num));
        max_int = 0;
        for (int i = 1;i <= n;i++)
        {
            int number, data;
            scanf("%d", &number);
            for (int j = 1;j <= number;j++)
            {
                scanf("%d", &data);
                num[data]++;
                if (num[data] > max_int)
                {
                    max_int = num[data];
                    index = data;
                }
                else if (num[data] == max_int && index > data)
                    index = data;
            }
        }
        if (max_int < m)
            printf("0\n");
        else
            printf("%d\n", index);
    }
    return 0;
}
