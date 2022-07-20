#include <iostream>
#include <cstdio>


using namespace std;

/*

给出样例总数t,对应每个样例 给出 n,m对应空的最小重量以及满时的最大重量 
然后给出硬币种类k，对应k种有对应的重量以及价值，求最小价值


完全背包的问题： 有N种物品和一个容量为V的背包，每种物品都有无限件可用。
第i种物品的费用是c[i]，价值是w[i]。
求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。　
这里背包的容量就为m-n,同时使求最小的价值，所以初始化dp为INF　　

*/



const int N = 1e4 + 10;

int main() {
    int t, e, f, n, v[N], w[N], dp[N];
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &e, &f, &n);
        for (int i = 0; i < n; i++) scanf("%d%d", &v[i], &w[i]);
        int m = f - e;  //硬币的重量
        fill(dp, dp + m + 1, INT_MAX / 10);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = w[i]; j <= m; j++) {
                dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        if (dp[m] == INT_MAX / 10) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[m]);
    }
    return 0;
}
