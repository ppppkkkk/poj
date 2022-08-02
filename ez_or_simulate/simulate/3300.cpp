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
自行车用链条将两个齿轮,前面的齿轮由2或3根齿条组成,后面的齿轮由5……10根齿条组成,
这齿轮转动的角速度d是由前后两个齿轮所包含的齿条数决定的,假设前面的齿轮的齿条数为m,后
面齿轮的齿条数为n,那么角速度为n/m,求出所有d后将其按升序排序,然后再计算d[i+1]/d[i]的最大值

*/
double front[15], rear[15];
double d[300];

int main()
{
    int n, r, k;
    double ans;
    while (cin >> n,n) {
        k = 0;
        ans = 0;
        memset(d, 0, sizeof(d));
        cin >> r;
        for (int i = 0; i < n; i++)
            cin >> front[i];
        for (int j = 0; j < r; j++)
            cin >> rear[j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < r; j++) 
                d[k++] = rear[j] / front[i];
                
        sort(d, d + k);
        for (int i = 1; i < k; i++)
            if (d[i] / d[i - 1] > ans)
                ans = d[i] / d[i - 1];
        printf("%.2lf\n", ans);
    }

    system("pause");
}
