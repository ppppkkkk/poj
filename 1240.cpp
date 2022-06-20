#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>

using namespace std;



/*
* 
poj 1240

由前序遍历和后序遍历推断出M叉树的数目

Sample Input

2 abc cba
2 abc bca
10 abc bca
13 abejkcfghid jkebfghicda
0
Sample Output

4
1
45
207352860
*/




const int maxn = 27;//26个字母

char s1[maxn];//前序
char s2[maxn];//后序
int m;//m叉树
int ans, pre;

int C(int cnt)//计算组合数
{
    int count = 1;
    for (int i = 1;i <= cnt;i++)
    {
        count *= (m - i + 1);
        count /= i;
    }
    return count;
}

void dfs(int pos, int end)
{
    int cnt = 0;
    for (int i = pos;i <= end;i++)
    {
        if (s2[i] == s1[pre])
        {
            cnt++;
            pre++;
            dfs(pos, i - 1);
            pos = i + 1;
        }
    }
    ans *= C(cnt);
}

int main()
{
    while (cin>>m,m)//m叉树
    {
        cin >> s1 >> s2;//前序和后序
        int len = strlen(s1);
        ans = pre = 1;
        dfs(0, len - 2);
        printf("%d\n", ans);
    }
    return 0;
}
