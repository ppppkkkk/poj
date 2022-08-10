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
将一个int范围的整数用-2进制表示并输出
*/
int n, k;
int a[1005];

int main() {
    scanf("%d", &n);
    if (n == 0) 
    {
        printf("0\n");
        return 0;
    }
    while (n) {
        int tmp = n % 2;
        if (n < 0) 
            tmp = -tmp;
        a[k++] = tmp;
        n = (n - tmp) / (-2);
    }
    for (int i = k - 1;i >= 0;--i)
        printf("%d", a[i]);
    printf("\n");
    return 0;
}
