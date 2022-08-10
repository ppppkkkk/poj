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
输入n层数字三角形，求从第一层到最后一层最大权值和。
*/

int f[360][360];
int a[360][360];
int main() {
    int n;
    while (cin>>n) 
    {
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= i;j++)
                scanf("%d", &a[i][j]);
        memset(f, 0, sizeof(f));
        f[1][1] = a[1][1];
        for (int i = 2;i <= n;i++)
            for (int j = 1;j <= i;j++) 
            {
                if (j == 1)
                    f[i][j] = f[i - 1][j] + a[i][j];
                else
                    f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + a[i][j];
            }
        int ans = 0;
        for (int i = 1;i <= n;i++)
            ans = max(ans, f[n][i]);
        printf("%d\n", ans);
    }
    return 0;
}
