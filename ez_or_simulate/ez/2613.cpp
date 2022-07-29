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
给出p,q,r,s，求c(p,q)/c(r,s)组合数公式
*/
int main()
{
    int p, q, r, s;
    while (cin>>p>>q>>r>>s)
    {
        double ans = 1;
        if (p - q < q)
            q = p - q;
        if (r - s < s) 
            s = r - s;
        for (int i = 1; i <= q || i <= s; i++) {
            if (i <= q)
                ans = ans * (p - i + 1) / i;
            if (i <= s)
                ans = ans * i / (r - i + 1);
        }

        printf("%.5f\n", ans);
    }

    return 0;
}
