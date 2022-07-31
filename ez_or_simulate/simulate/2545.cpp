#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;
/*
给定三个数a、b、c，构造一个序列，这个序列的元素的质因数只能是a或b或c，求这个序列的第n个数。
*/



long long s[10000];
int main() {
    int p1, p2, p3;
    long long k;
    int a, b, c, n;
    scanf("%d %d %d %d", &a, &b, &c, &n);
    s[1] = p1 = p2 = p3 = 1;
    for (int i = 1;i <= n;i++) {
        k = min(min(s[p1] * a, s[p2] * b), s[p3] * c);
        s[i + 1] = k;
        if (k == s[p1] * a)
            p1++;
        if (k == s[p2] * b)
            p2++;
        if (k == s[p3] * c)
            p3++;
    }
    printf("%lld\n", k);
    return 0;
}

