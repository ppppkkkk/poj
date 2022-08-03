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

const int INF = 0x3f3f3f3f;

int main() {
    int n, maxv, maxi, minv, mini, a, b, c, v;
    char data[10][10];
    while (cin >> n, n != -1) {
        maxv = -1;
        minv = 1000;
        for (int i = 0;i < n;i++) {
            scanf("%d%d%d", &a, &b, &c);
            scanf("%s", data[i]);
            v = a * b * c;
            if (maxv < v) {
                maxv = v;
                maxi = i;
            }
            if (minv > v) {
                minv = v;
                mini = i;
            }
        }
        printf("%s took clay from %s.\n", data[maxi], data[mini]);
    }
    return 0;
}
