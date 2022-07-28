#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;

/*
商店有面值为25分、10分、5分、1分的硬币，
给出各硬币的数量和要找给顾客的钱数，问怎么使找给顾客的总的硬币数最少。
*/


int num[4], tmp[4], result[4];
int total, money;

bool success;

void DFS(int depth, int remained)
{
    if (depth == 4)//四种硬币已经为0
    {
        if (remained == 0)//剩余钱数为0
        {
            int sum = tmp[0] + tmp[1] + tmp[2] + tmp[3];
            if (sum < total)
            {
                for (int i = 0;i < 4;i++)
                    result[i] = tmp[i];
                total = sum;
            }
            success = true;
        }
        return;
    }
    for (int j = 0;j < num[depth]+1;j++)
    {
        tmp[depth] = j;
        if (depth == 0)
            DFS(depth + 1, remained - 25 * j);
        else if (depth == 1)
            DFS(depth + 1, remained - 10 * j);
        else if (depth == 2)
            DFS(depth + 1, remained - 5 * j);
        else if (depth == 3)
            DFS(depth + 1, remained - j);
    }
}
int main()
{
    while (scanf("%d%d%d%d%d", &num[0], &num[1], &num[2], &num[3], &money))
    {
        if (num[0] + num[1] + num[2] + num[3] + money == 0)
            break;
        total = 100000;
        success = false;
        DFS(0, money);
        if (success)
            printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies.\n", result[0], result[1], result[2], result[3]);
        else
            printf("Cannot dispense the desired amount.\n");
    }
    return 0;
}
