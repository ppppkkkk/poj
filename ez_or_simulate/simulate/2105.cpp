#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
using namespace std;


int main() {
    int n, ans[4], t;
    string a;
    scanf("%d", &n);
    while (n--) {
        cin >> a;
        memset(ans, 0, sizeof(ans));
        for (int i = 0;i < 4;i++)
        {
            t = 128;
            for (int j = 0;j < 8;j++) 
            {
                ans[i] += t * (a[i * 8 + j] - '0');
                t /= 2;
            }
        }
        for (int i = 0;i < 3;i++) 
        {
            printf("%d.", ans[i]);
        }
        printf("%d\n", ans[3]);
    }
    return 0;
}
