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
给你一个数列，求数列中两个不重叠的子序列的最大和。
*/

int main()
{
     int left[100001];
     int right[100001];
     int a[100001];
     int n;
     while (cin>>n , n)
     {
         for (int i = 0;i < n;i++)
         {
             scanf("%d", &a[i]);
         }
         int sumL = 0;
         int max = -0x7fffffff;
         for (int i = 0;i < n;i++)//从左向右求到i结尾的最大连续子串的最大值   
         {
             sumL = sumL + a[i];
             if (sumL > max)
             {
                 max = sumL;
             }
             if (sumL < 0)
             {
                 sumL = 0;
             }
             left[i] = max;
         }
         max = -0x7fffffff;
         int ans = -0x7fffffff;
         int sumR = 0;
         for (int i = n - 1;i >= 1;i--)
         {
             sumR = sumR + a[i];
             if (sumR > max)
             {
                 max = sumR;
             }
             if (sumR < 0)
             {
                 sumR = 0;
             }
             if (ans < max + left[i - 1])
             {
                 ans = max + left[i - 1];
             }
         }
         printf("%d\n", ans);
     }
     return 0;
}
