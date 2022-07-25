#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
输入一组数，问连续素数和等于它的有几种情况
*/
int prime(int n)
{
    for (int i = 2;i <= sqrt(n*1.0);i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int a[10005];

int main()
{
    for (int i = 2, j = 0;i < 10005; i++) 
        if (prime(i))
            a[j++] = i;

    int n;
    while (cin >> n, n) {
        int sum = 0, ans = 0;
        for (int i = 0;i < 10005; i++) {
                sum = 0;
            if (a[i] > n)
                break;
            for (int j = i;j < 10005 && sum < n; j++) {
                sum += a[j];
                if (sum == n) {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

