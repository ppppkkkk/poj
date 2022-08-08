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
s*s的正方形上有n个点，求一个圆将它们覆盖但不超出正方形，要求圆的x坐标尽可能小，其次y坐标尽可能小。
*/
int po[60][2];//两种狗
int s, n;
bool solve(int x, int y)
{
     int len = min(min(x, y), min(s - x, s - y));
     len = len * len;
     for (int i = 0;i < n;i++)
     {
         int xx = po[i][0], yy = po[i][1];
         if ((xx == x && yy == y) || ((xx - x) * (xx - x) + (yy - y) * (yy - y)) > len)
             return false;
     }
     return true;
 }
int main()
{
     int T;
     cin >> T;
     while(T--)
     {
         scanf("%d%d", &s, &n);
         for (int i = 0;i < n;i++)
             scanf("%d%d", &po[i][0], &po[i][1]);
         int flag = 0;
         for (int x = 1;x < s;x++)
         {
             for (int y = 1;y < s;y++)
             {
                 if (solve(x, y))
                 {
                     flag = true;
                     printf("%d %d\n", x, y);
                     x = y = s;
                 }
             }
         }
         if (!flag)
             printf("poodle\n");
     }
     return 0;
}
