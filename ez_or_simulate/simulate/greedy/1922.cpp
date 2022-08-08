#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
#include <queue>
using namespace std;
/*
起点与终点相隔4500米。现Charley 需要从起点骑车到终点。
但是，他有个习惯，沿途需要有人陪伴，即以相同的速度， 与另外一个人一起骑。
而当他遇到以更快的速度骑车的人时，他会以相应的速度跟上这个更快的人。
先给定所有与Charley 同路的人各自的速度与出发时间，问Charley 以这种方式跟人，骑完4500米需要多少时间。
得出的结果若是小数，则向上取整。
greedy
*/

int main()
{
    int N, V, T, ans;
    while (scanf("%d", &N),N)
    {
        ans = 0x7fffffff;
        for (int i = 0;i < N;i++)
        {
            scanf("%d%d", &V, &T);
            if (T >= 0 && ceil(4.5 * 3600 / V) + T < ans)
                ans = ceil(4.5 * 3600 / V) + T;
        }
        printf("%d\n", ans);
    }
    return 0;
}
