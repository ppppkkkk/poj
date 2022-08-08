#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
/*
按照题意处理字符串
*/

#define maxn 30

char order[maxn];
char st[maxn];
int l;

void solve(char ch)
{
    char temp;
    switch (ch)
    {
    case 'J':
        temp = st[l - 1];
        for (int i = l - 1; i > 0; i--)
            st[i] = st[i - 1];
        st[0] = temp;
        break;
    case 'C':
        temp = st[0];
        for (int i = 0; i < l - 1; i++)
            st[i] = st[i + 1];
        st[l - 1] = temp;
        break;
    case 'E':
        for (int i = 0; i < l / 2; i++)
            swap(st[i], st[i + l / 2 + (l & 1)]);
        break;
    case 'A':
        reverse(st, st + l);
        break;
    case 'P':
        for (int i = 0; i < l; i++)
            if (st[i] <= '9' && st[i] >= '0')
                st[i] = (st[i] - '0' + 9) % 10 + '0';
        break;
    case 'M':
        for (int i = 0; i < l; i++)
            if (st[i] <= '9' && st[i] >= '0')
                st[i] = (st[i] - '0' + 1) % 10 + '0';
        break;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", order);
        scanf("%s", st);
        l = strlen(st);
        for (int i = strlen(order) - 1; i >= 0; i--)
            solve(order[i]);
        printf("%s\n", st);
    }
    return 0;
}
