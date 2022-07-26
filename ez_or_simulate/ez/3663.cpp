#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
给你一堆数和一个限定的空间大小，要求求出两个数的和小于等于空间大小的对数
*/

int main() {
    int n, s, ans=0, data[20001];
    scanf("%d%d", &n, &s);
    for (int i = 0;i < n;i++)
        scanf("%d", &data[i]);
    sort(data, data + n);
    for (int i = 0;i < n;i++) {
        if (data[i] >= s)break;
        for (int j = 0;j < i;j++)
            if (data[i] + data[j] <= s)
                ans++;
    }
    printf("%d\n", ans);
    return 0;
}
