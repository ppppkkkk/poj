#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;
/*
就是这个数反转过来相加若相等刚输出true,否则false
*/



int que[40000] = { 0 };
int ans[3000];

int main() {
    int p, n = 0;
    for (int i = 2; i < 40000 && n < 3000;i++)
    {
        if (!que[i])
        {
            ans[n++] = i;
            for (int j = i + 1, p = 0;j < 40000;j++)
            {
                if (!que[j])
                {
                    p++;
                    if (p == i)
                    {
                        que[j] = 1;
                        p = 0;
                    }
                }
            }
        }
    }
    int T;
    while (scanf("%d", &T) , T)
        printf("%d\n", ans[T - 1]);

    return 0;
}
