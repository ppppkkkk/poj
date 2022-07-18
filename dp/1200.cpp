include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

/*
给定字符串、n和m，字符串里最多有m个不同的字符，问长度为n的不同子串最多有几个

Sample Input
3 4
daababac

Sample Output
5

*/
const int maxn = 16000001;

int has[maxn];
int num[300];
//给定字符串s和n和m
char s[maxn];
int n, m;

void init()
{
    int len = strlen(s);
    int z = 0;
    num[s[0]] = z++;
    for (int i = 1;i < len;i++)
    {
        if (num[s[i]] == 0)
            num[s[i]] = z++;
    }
}
int getHas(int l, int r)
{
    int sum = 0;
    for (int i = l;i <= r;i++)
    {
        sum = sum * m + num[s[i]];
    }
    return sum;
}
int main()
{
    while (~scanf("%d%d%s", &n, &m, s))
    {
        int ans = 0;
        int len = strlen(s);
        init();
        for (int i = 0;i <= len - n;i++)
        {
            int cnt = getHas(i, i + n - 1);
            if (!has[cnt])
            {
                ans++;
                has[cnt] = 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
