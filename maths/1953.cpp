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
输入一个数n，只由0和1组成的长度为n的序列，其中1不相邻的序列有多少种
Fibonacci通项公式解法
*/

int main() {
    int t, Case=1;
    long long n;
    double ans;
    scanf("%d", &t);
    while (Case <= t) {
        scanf("%lld", &n);
        printf("Scenario #%d:\n", Case++);
        ans = (pow((1 + sqrt(5.0)) / 2, (double)n + 2) - pow((1 - sqrt(5.0)) / 2, (double)n + 2)) / sqrt(5.0);
        printf("%.0llf\n\n", ans);
    }
    return 0;
}
