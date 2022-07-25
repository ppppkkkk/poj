#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
前面给出N和N个数，中间一串字符串（分割用），后面给出M和M个询问，问第I小的数字是多少

*/




int main()
{
    int n, a[1000001];
    int m;
    char s[101];
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    scanf("%s", s);
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &n);
        printf("%d\n", a[n - 1]);
    }
}
