#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 505
char sa[maxn], sb[maxn];
int num[maxn];

/*
已知：位数为K（0 < K <200）的N进制数P（2 ≤ N ≤62），该数由0-9, A-Z, a-z组成，其中A-Z代表10-35，a-z代表36-61
求：转换为M进制（2 ≤ M ≤62）后的新数Q
*/
inline int c_d(char c)//字符转数
{
    if ('A' <= c && c <= 'Z')
        return c - 'A' + 10;
    else if ('a' <= c && c <= 'z')
        return c - 'a' + 36;
    return c - '0';
}

inline char d_c(int d)//数转字符
{
    if (10 <= d && d <= 35)
        return d - 10 + 'A';
    else if (36 <= d && d <= 61)
        return d - 36 + 'a';
    return d + '0';
}

int main()
{
    int t, a, b;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &a, &b);
        scanf(" %s", sa);
        int la = strlen(sa), lb = 0;
        for (int i = 0; i < la; ++i)
            num[i] = c_d(sa[la - 1 - i]);
        while (la)
        {
            for (int i = la - 1; i; --i)
            {
                num[i - 1] += num[i] % b * a;
                num[i] /= b;
            }
            sb[lb++] = d_c(num[0] % b);
            num[0] /= b;
            while (la > 0 && !num[la - 1])
                --la;
        }
        int l = 0, r = lb - 1;
        while (l < r)
        {
            swap(sb[l], sb[r]);
            ++l;
            --r;
        }
        sb[lb] = '\0';
        printf("%d %s\n%d %s\n\n", a, sa, b, sb);
    }
}
