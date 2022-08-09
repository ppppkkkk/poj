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
题意：给定不共线的三点坐标，求其外接圆的周长。
思路：通过坐标可以求出三点围成三角形的面积S。根据正弦定理有a/sinA = 2*R，根据面积公式有S = (bcsinA)/2。消去sinA可得关于R的等式，进而可求周长。
*/


#define PI acos(-1.0)
double dis(double a, double b, double c, double d) {
    return sqrt((c - a) * (c - a) + (d - b) * (d - b));
}
int main() {
    double a, b, c, d, e, f;
    while (scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f) != EOF) {
        double s = fabs(a * d + b * e + c * f - d * e - a * f - b * c);
        printf("%.2f\n", PI * dis(a, b, c, d) * dis(a, b, e, f) * dis(c, d, e, f) / s);
    }
    return 0;
}
