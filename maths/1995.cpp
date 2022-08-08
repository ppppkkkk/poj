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
就是求(A1^ B1+A2^ B2+ … +AH^ BH)mod M
(a*b) % p = (a % p * b % p) % p
*/

int power(int a, int b, int p) {
    int ans = 1 % p;
    for (; b; b >>= 1) {
        if (b & 1)ans = (long long)ans * a % p;
        a = (long long)a * a % p;
    }
    return ans;
}
int main() {
    int t, p, n, ans, x, y;
    cin >> t;
    while(t--) {
        scanf("%d%d", &p, &n);
        ans = 0;
        for (int i = 1; i <= n; i++) 
        {
            scanf("%d%d", &x, &y);
            ans = (ans + power(x, y, p)) % p;
        }
        printf("%d\n", ans);
    }
    return 0;
}
