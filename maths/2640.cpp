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
给定若干条边，问能否用其中的一些组成多边形。
先排序，看前i个的和是否大于第i+1个，若大于则可以
*/

double a[30];
int main()
{
    int  n;
    while (cin>>n,n)
    {
        memset(a, 0, sizeof(a));
        for (int i = 0;i < n;i++)
        {
            scanf("%lf", &a[i]);
        }
        sort(a, a + n);
        double sum = 0;
        int flag = 0;
        for (int i = 0;i < n;i++)
        {
            if (sum >= a[i])
            {
                flag = 1;
                printf("YES\n");
                break;
            }
            sum += a[i];
        }
        if (flag == 0)
        {
            printf("NO\n");
        }
    }
    return 0;
}
