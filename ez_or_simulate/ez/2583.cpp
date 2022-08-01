#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;
//f(x) = Ax2 + Bx + C，给出f(0), f(1), f(2)，算出f(3), f(4), f(5)
int main()
{
    double a, b, c;
    int x, y, z;
    while (cin>>x>>y>>z)
    {
        a = (z + x - 2 * y) * 1.0 / 2;
        b = 2 * y - z * 1.0 / 2 - 3 * x * 1.0 / 2;
        c = x;
        printf("%.0lf %.0lf %.0lf\n", 9 * a + 3 * b + c,
            16 * a + 4 * b + c, 25 * a + 5 * b + c);
    }
    return 0;
}
