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
给出n根承重不同的绳子，选出几根使得承重最大且没有绳子断裂
*/

bool cmp(int a, int b)
{
    return a > b;
}


int a[1001];
int main()
{
    int T;
    int n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a+1,1+a + n,cmp);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, a[i] * i);
        }
        printf("%d\n", ans);
    }
    return 0;

}
