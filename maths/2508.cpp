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
两个点在扇形中的夹/在立体中的夹角=扇形圆心角/2pi；

再根据余弦定理求得
*/
double PI = acos(-1.0);
int main()
{
    double r, h, l, p1, p2, th1, th2, dt;
    while (scanf("%lf%lf%lf%lf%lf%lf", &r, &h, &p1, &th1, &p2, &th2) != EOF)
    {
        dt = fabs((th1 - th2) / 180.0) * PI;
        while (dt > 2 * PI)
            dt -= 2 * PI;
        if (dt > PI)
            dt = 2 * PI - dt;
        l = sqrt(h * h + r * r);
        printf("%.2lf\n", sqrt(p1 * p1 + p2 * p2 - 2.0 * p1 * p2 * cos(dt * r / l)));
    }
    return 0;
}
