#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
/*
给定一个矩形，内部每个点有权值，多次询问一个子矩形内部权值和
*/


int main()
{
    int T;
    int mat[1001][1001];
    scanf("%d", &T);
    while (T--)
    {
        int m, n;//行数，座位数
        scanf("%d%d", &m, &n);
        for (int i = 0;i <m;i++)
            for (int j = 0;j <n;j++)
                scanf("%d", &mat[i][j]);
        int t;
        scanf("%d", &t);
        while (t--)
        {
            int ans = 0;
            int r1, r2, s1, s2;//矩形的四个位置
            scanf("%d%d%d%d", &r1, &r2, &s1, &s2);
            for (int i = r1-1 ;i < s1;i++)
                for (int j = r2-1 ;j < s2;j++)
                    ans += mat[i][j];
            printf("Absolutni hodnota pohodlnosti je %d bodu.\n", ans);
        }
        if (T)
            printf("\n");
    }
    return 0;
}
