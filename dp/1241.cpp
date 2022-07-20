
#include <stdio.h>
#include <cstring>
#define maxn 100000

/*
有2^n运动员，两两分别进行一场比赛，胜的人可以继续比赛，
这样就可以形成一颗完全二叉树，求树中任意给定的一个结点的最好名次和最差名次。

先按二叉树的顺序进行存图。然后从上到下扫描输了几个人。
在结果累计保存到儿子节点。
再从下往上扫描赢了几个人。再把左右儿子的节点保存到父亲节点。
*/

int a[maxn];
struct st
{
    int l, r;
}s[maxn];


int main()
{
    int n;
    int ca = 0;
    while (scanf("%d", &n) == 1 && n)
    {
        if (ca == 1) printf("\n");
        ca = 1;
        int m = 1 << n;
        for (int i = m; i <= 2 * m; i++)
            a[i] = i - m + 1;
        int num = m >> 1;
        for (int k = 1; k <= n; k++)
        {
            for (int i = num; i < 2 * num; i++)
                scanf("%d", &a[i]);
            num = num >> 1;
        }
        memset(s, 0, sizeof(s));
        for (int i = 1;i <= ((1 << n) - 1);i++)//输了几个人
        {
            if (a[i] != a[i << 1]) s[a[i << 1]].l = s[a[i]].l + 1;
            if (a[i] != a[i << 1 | 1]) s[a[i << 1 | 1]].l = s[a[i]].l + 1;
        }
        for (int i = ((1 << n) - 1);i >= 1;i--)//赢了几个人
        {
            if (a[i] != a[i << 1]) s[a[i]].r = s[a[i << 1]].r + s[a[i << 1 | 1]].r + 1;
            if (a[i] != a[i << 1 | 1]) s[a[i]].r = s[a[i << 1]].r + s[a[i << 1 | 1]].r + 1;
        }
        int sum = 1 << n;
        s[a[1]].r = sum - 1;
        int t, p;
        scanf("%d", &t);
        while (t--)
        {
            scanf("%d", &p);
            printf("Player %d can be ranked as high as %d or as low as %d.\n", p, 1 + s[p].l, sum - s[p].r);
        }
    }
    return 0;
}
