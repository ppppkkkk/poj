#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
题目大意：给你一个被n块挡板分隔成n+1个区域的盒子，给你m个点，从小到大输出含有点的个数的区域有多少个
设矢量P = ( x1, y1 )，Q = ( x2, y2 )，则P × Q = x1*y2 - x2*y1，其结果是一个标量

显然有性质 P × Q = - ( Q × P ) 和 P × ( - Q ) = - ( P × Q )。

叉积的一个非常重要性质是可以通过叉积的符号判断两个矢量相互之间的顺逆时针关系：

若 P × Q > 0 , 则P在Q的顺时针方向。即P在Q的右侧，Q在P的左侧。
若 P × Q < 0 , 则P在Q的逆时针方向。即P在Q的左侧，Q在P的右侧。
若 P × Q = 0 , 则P与Q共线，但可能同向也可能反向。

*/



struct Point
{
    long long int x, y;
};

struct Line
{
    Point a, b;
} line[5005];

long long int cnt[1005], cnt1[1010];

int Multi(Point p1, Point p2, Point p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

bool cmp(Line a, Line b)
{
    return a.a.x < b.a.x;
}

void BinarySearch(Point a, int n)
{
    int l, r, mid;

    l = 0; r = n - 1;

    while (l < r)
    {
        mid = (l + r) >> 1;
        if (Multi(a, line[mid].a, line[mid].b) > 0)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    if (Multi(a, line[l].a, line[l].b) < 0)
    {
        cnt[l]++;
    }
    else
    {
        cnt[l + 1]++;
    }
}

int main()
{
    int n, m, x1, y1, x2, y2;
    int i, t1, t2;
    Point a;

    while (cin >> n && n)
    {
        cin >> m >> x1 >> y1 >> x2 >> y2;
        for (i = 0; i < n; i++)
        {
            cin >> t1 >> t2;
            line[i].a.x = t1;
            line[i].a.y = y1;
            line[i].b.x = t2;
            line[i].b.y = y2;
        }

        sort(line, line + n, cmp);

        memset(cnt, 0, sizeof(cnt));
        memset(cnt1, 0, sizeof(cnt1));
        for (i = 0; i < m; i++)
        {
            cin >> a.x >> a.y;
            BinarySearch(a, n);
        }

        cout << "Box" << endl;
        for (int i = 0; i <= n; i++)
        {
            if (cnt[i])
            {
                cnt1[cnt[i]]++;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            if (cnt1[i])
            {
                printf("%d: %I64d\n", i, cnt1[i]);
            }
        }
    }
}

