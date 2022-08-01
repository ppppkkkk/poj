#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;

struct word
{
    char a[20];//单词 
    int value;//值 
}w[10000];
char str[1001];

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0;i < m;i++) {
        scanf("%s%d", &w[i].a, &w[i].value);
    }
    while (n--) {
        int sum = 0;
        for (int i = 0;;i++) {
            scanf("%s", str);
            for (int j = 0;j < m;j++)
                if (!strcmp(str, w[j].a))
                    sum += w[j].value;
            if (!strcmp(str, "."))
                break;
        }
        printf("%d\n", sum);
    }
    return 0;
}
