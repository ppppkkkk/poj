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
快排求中位数
*/
#define MAXN 250002

long long a[MAXN];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }

    sort(a, a + n);
    if (n % 2)
        printf("%lld.0\n", a[n / 2]);
    else {
        printf("%.1lf\n", (double)(a[n / 2] + a[(n / 2) - 1]) / 2);
    }

    return 0;
}
