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
给定n和k，有一个一元n次方程，由0次幂开始给定系数。用这个式子去除以x^k+1，求剩下的一元n-k次方程。
*/



int a[10005], h[10005];//  多项式a/多项式b
int main()
{
    int n, k;
    while (~scanf("%d%d", &n, &k),n!=-1,k!=-1) {
        for (int i = 0;i <= n;i++) {
            scanf("%d", &a[i]);
        }
        for (int i = n;i >= k;i--) {
            if (a[i] != 0) {
                a[i - k] -= (a[i]);
                a[i] = 0;
            }
        }
        while (a[n] == 0 && n >= 0) {
            n--;
        }
        for (int i = 0;i < n;i++) {
            cout << a[i] << " ";
        }
        cout << a[n] << endl;
    }
    return 0;
}
