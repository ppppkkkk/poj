#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define eps 1e-8

/*
题意：给出4个顶点，表示两条直线，求这两条直线的相交情况，重合输出LINE，平行输出NONE，相交于一点输出该点的距离。

用叉积判断直线的重合和平行，并且可以用叉积求相交直线的交点。
用叉积求直线交点的模板：

double t=((a-c)^(c-d))/((a-b)^(c-d));
ans=Point(a.x+(b.x-a.x)*t,a.y+(b.y-a.y)*t)
*/

int n;
struct Point
{
    double x, y;
}p1, p2, p3, p4;
double mul(Point p1, Point p2, Point p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}
int main()
{
    scanf("%d", &n);
    printf("INTERSECTING LINES OUTPUT\n");
    while (n--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &p4.x, &p4.y);
        if (fabs(mul(p1, p2, p3)) < eps && fabs(mul(p1, p2, p4)) < eps)
            printf("LINE\n");
        else if ((p2.x - p1.x) * (p4.y - p3.y) == (p2.y - p1.y) * (p4.x - p3.x))
            printf("NONE\n");
        else
        {
            double a1 = p1.y - p2.y;
            double b1 = p2.x - p1.x;
            double c1 = p1.x * p2.y - p2.x * p1.y;
            double a2 = p3.y - p4.y;
            double b2 = p4.x - p3.x;
            double c2 = p3.x * p4.y - p4.x * p3.y;
            double x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
            double y = (a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1);
            printf("POINT %.2lf %.2lf\n", x, y);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
