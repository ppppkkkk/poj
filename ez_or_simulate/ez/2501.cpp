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

int main()
{
    char   in[128];
    int    c, h, m, s, t0 = 0, t1 = 0;
    double d = 0, v0 = 0, v1 = 0;
    while (gets_s(in)) {
        c = sscanf(in, "%d:%d:%d %lf", &h, &m, &s, &v1);
        t1 = h * 3600 + m * 60 + s;
        d += v0 * (t1 - t0) / 3600;
        t0 = t1;
        if (c == 3)
            printf("%.2d:%.2d:%.2d %.2f km\n", h, m, s, d);
        else v0 = v1;
    }
    return 0;
}
