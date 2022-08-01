#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;

double PI=acos(-1.0);
int main() {
    double V, d, D;
    while (scanf("%lf%lf", &D, &V) == 2 && D) {
        d = pow(D * D * D - V * 6 / PI, 1.0 / 3);
        printf("%.3lf\n", d);
    }
    return 0;
}
