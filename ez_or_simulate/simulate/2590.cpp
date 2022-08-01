#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;

int main() {
    long long n, x, y, s, n1, ans;
    scanf("%lld", &n);
    while (n--) {
        scanf("%lld%lld", &x, &y);
        s = y - x;
        n1 = floor((double)pow((double)s, 0.5));
        if (s == 0)
            ans = 0;
        else if ((n1 - 1) * n1 < s && s <= n1 * n1)
            ans = 2 * n1 - 1;
        else if (n1 * n1 < s && s <= n1 * (n1 + 1))
            ans = 2 * n1;
        else if (n1 * (n1 + 1) < s && s <= (n1 + 1) * (n1 + 1))
            ans = 2 * n1 + 1;
        printf("%lld\n", ans);
    }
    return 0;
}
