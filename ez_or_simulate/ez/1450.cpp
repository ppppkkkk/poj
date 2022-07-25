#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
给一个m*n的矩阵，每个小正方形都有一个镇子。问遍历所有镇子并回到起点的最小路径长度。
找规律:如果m或n为偶数，那么等于m*n，否则，需要走一个对角线
*/

int main()
{
    int t;
    cin >> t;
    for (int i = 0;i < t;i++)
    {
        int a, b;
        cin >> a >> b;
        double num = a * b;
        if (a % 2 == 1 && b % 2 == 1)
        {
            num += sqrt(2.0) - 1;
            printf("Scenario #%d:\n%.2f\n\n", i + 1, num);
        }
        else
            printf("Scenario #%d:\n%.2f\n\n", i + 1, num);
    }
    return 0;
}

