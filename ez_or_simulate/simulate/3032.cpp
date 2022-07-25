#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include<queue>

using namespace std;
/*
给你一副牌（不大于13张且从A依次增加）。
第一次，将最上面的牌移动到最下面。
第二次，将最上面的牌移动到最下面，重复1次（共2次）
第三次，将最上面的牌移动到最下面，重复2次（共3次）
……
直到就剩1张牌。
保证出现的次序为A,2,3,4,5,6,7,8,9,10,J,Q,K
问初始时刻放置牌的顺序。

出入队
*/

queue<int> q;
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int m, a[15], t;
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            q.push(m - i);
            for (int j = 0; j < m - i; j++)
            {
                q.push(q.front());
                q.pop();
            }
        }
        t = m - 1;
        while (!q.empty())
        {
            a[t--] = q.front();
            q.pop();
        }
        for (int i = 0; i < m; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}
