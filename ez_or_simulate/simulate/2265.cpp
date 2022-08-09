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
给你两个蜂巢的编号，给你一个的编号让你输出在另外一个蜂巢中对应的编号
*/


int main()
{
	int a;
     while (scanf("%d", &a) != EOF)
     {
         if (a == 1)
         {
             printf("0 0\n");
             continue;
         }
         int n = 0;
         while (3 * (n - 1) * n + 1 < a)//3 * (n-1) * n + 1表示第n圈的最后一个数是多少
             n++;//找到该数属于第几圈
        n--;
        a -= 3 * (n - 1) * n + 1;
		int x, y;
         //分为6个边，每个边上n个数，可以根据题目里的两个图找找规律，看看每条边上的xy的规律是多少
         if (a <= n)
         {
             x = n - a;
             y = a;
         }
         else if (a > n && a <= 2 * n)
		 {
             x = n - a;
             y = n;
         }
         else if (a > 2 * n && a <= 3 * n)
         {
             x = -n;
             y = 3 * n - a;
         }
         else if (a > 3 * n && a <= 4 * n)
         {
             x = a - 4 * n;
             y = 3 * n - a;
         }
         else if (a > 4 * n && a <= 5 * n)
         {
            x = a - 4 * n;
            y = -n;
         }
         else
         {
             x = n;
            y = a - 6 * n;
         }
		printf("%d %d\n", x, y);
     }
     return 0;
}
