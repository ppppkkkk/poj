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
给出该多边形的每条边的中点,要求该多边形的每个端点坐标
*/
struct Point
{
    double x, y;
}P[1001], S[1001];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        S[0].x = S[0].y = 0;
        for (int i = 0;i < n;++i)
        {
            scanf("%lf%lf", &P[i].x, &P[i].y);
            if (i % 2)
            {
                S[0].x -= P[i].x;
                S[0].y -= P[i].y;
            }
            else
            {
                S[0].x += P[i].x;
                S[0].y += P[i].y;
            }
        }
        for (int i = 1;i < n;++i)
        {
            S[i].x = P[i - 1].x * 2 - S[i - 1].x;
            S[i].y = P[i - 1].y * 2 - S[i - 1].y;
        }
        printf("%d", n);
        for (int i = 0;i < n;++i) 
            printf(" %.6lf %.6lf", S[i].x, S[i].y);
        printf("\n");
    }
    return 0;
}
