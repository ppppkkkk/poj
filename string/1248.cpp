#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
给定字符串，从字符串中选择字符转换成整形满足密码公式，要求输出结果按照最大字典序输出
poj 1248
*/

bool cmp(char a, char b) {
    return a > b;
}
int deal(int v, int w, int x, int y, int z,int ans) {
    if (v - w * w + x * x * x - y * y * y * y + z * z * z * z * z == ans)
        return 1;
    else
        return 0;
}

void solve(int len,char s[],int ans) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (i == j)
                continue;
            for (int x = 0; x < len; x++) {
                if (x == i || x == j)
                    continue;
                for (int y = 0; y < len; y++) {
                    if (y == j || y == x || y == j)
                        continue;
                    for (int z = 0; z < len; z++) {
                        if (z == i || z == j || z == x || z == y)
                            continue;
                        if (deal(s[i] - 'A' + 1, s[j] - 'A' + 1, s[x] - 'A' + 1, s[y] - 'A' + 1, s[z] - 'A' + 1,ans)) {
                            printf("%c%c%c%c%c\n", s[i], s[j], s[x], s[y], s[z]);
                            return;
                        }
                    }
                }
            }
        }
    }
    printf("no solution\n");
}

int main()
{
    int len;
    int ans;
    char s[30];
    while (cin>>ans>>s, ans)
    {
        len = strlen(s);
        sort(s, s+len, cmp);
        solve(len,s,ans);
    }
    return 0;
}

