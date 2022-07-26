#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

/*
在一堆字母中找一段字母，使其中至少含有1个原音，2个辅音字母，
且按字典序从小到大排列
*/

int L, C;//L一段字母长度 C总长度
char ch[30];
int vis[30];
void dfs(int num, int step, int len1, int len2)
{//len1元音 len2辅音
    if (step == L)
    {
        if (len1 >= 1 && len2 >= 2)
        {
            for (int j = 0;j < C;j++)
                if (vis[j])
                    cout << ch[j];
            cout << endl;
        }
        return;
    }
    for (int i = num;i < C;i++)
    {
        if (!vis[i] && ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u')
        {//元音
            vis[i] = 1;
            dfs(i + 1, step + 1, len1 + 1, len2);
            vis[i] = 0;
        }
        else
        {//辅音
            vis[i] = 1;
            dfs(i + 1, step + 1, len1, len2 + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    scanf("%d%d", &L, &C);
    for (int i = 0;i < C;i++)
        cin >> ch[i];
    sort(ch, ch + C);
    memset(vis, 0, sizeof(vis));
    dfs(0, 0, 0, 0);
    return 0;
}
