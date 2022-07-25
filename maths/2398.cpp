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



const double pi = acos(-1.0);
const int maxn = 1e3 + 7;
int ans[maxn], num[maxn];

struct Point {
    int x, y;
    Point() {}
    Point(int _x, int _y) { x = _x;y = _y; }
};

struct Line {
    Point a, b;
    Line() {}
    Line(Point _a, Point _b) { a = _a;b = _b; }
}line[maxn];

bool cmp(Line u, Line v)
{
    return  u.a.x < v.a.x;
}

//求叉积*
int cross(Point a, Point b, Point c)
{
    a.x -= c.x;a.y -= c.y;
    b.x -= c.x;b.y -= c.y;
    return a.x * b.y - a.y * b.x;
}

int main()
{
    int n, m, x1, y1, x2, y2;
    while (~scanf("%d", &n) && n)
    {
        memset(ans, 0, sizeof(ans));
        memset(ans, 0, sizeof(num));
        scanf("%d%d%d%d%d", &m, &x1, &y1, &x2, &y2);
        for (int i = 0;i < n;i++)
        {
            int Ui, Li;
            scanf("%d%d", &Ui, &Li);
            line[i] = Line(Point(Ui, y1), Point(Li, y2));
        }
        line[n] = Line(Point(x2, y1), Point(x2, y2));
        sort(line, line + n + 1, cmp);
        Point s;
        while (m--)
        {
            scanf("%d%d", &s.x, &s.y);
            int l = 0, r = n;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (cross(line[mid].b, line[mid].a, s) > 0)
                    r = mid - 1;
                else l = mid + 1;
            }
            ans[l]++;
        }
        for (int i = 0;i <= n;i++)
            if (ans[i]) num[ans[i]]++;
        printf("Box\n");
        for (int i = 1;i <= n;i++)
            if (num[i]) printf("%d: %d\n", i, num[i]);
    }
    return 0;
}
