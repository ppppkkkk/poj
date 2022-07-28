#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;

/*
单词的前后缀都有其特殊含义，现在给出一些可能有前后缀的单词以及每个前后缀的含义（如下表），
输出经”翻译”后的字符串（每个单词最多有一种前缀和一种后缀）
*/


char c[101];
int f1, f2;
void deal()
{
    if (!f1 && c[0] == 'a' && c[1] == 'n' && c[2] == 't' && c[3] == 'i')
    {
        f1 = 1;
        strcpy(c, c + 4);
        deal();
        return;
    }
    if (!f1 && c[0] == 'p' && c[1] == 'o' && c[2] == 's' && c[3] == 't')
    {
        f1 = 2;
        strcpy(c, c + 4);
        deal();
        return;
    }
    if (!f1 && c[0] == 'p' && c[1] == 'r' && c[2] == 'e')
    {
        f1 = 3;
        strcpy(c, c + 3);
        deal();
        return;
    }
    if (!f1 && c[0] == 'r' && c[1] == 'e')
    {
        f1 = 4;
        strcpy(c, c + 2);
        deal();
        return;
    }
    if (!f1 && c[0] == 'u' && c[1] == 'n')
    {
        f1 = 5;
        strcpy(c, c + 2);
        deal();
        return;
    }
    int len = strlen(c);
    if (!f2 && len >= 2 && c[len - 2] == 'e' && c[len - 1] == 'r')
    {
        f2 = 1;
        c[len - 2] = '\0';
        deal();
        return;
    }
    if (!f2 && len >= 3 && c[len - 3] == 'i' && c[len - 2] == 'n' && c[len - 1] == 'g')
    {
        f2 = 2;
        c[len - 3] = '\0';
        deal();
        return;
    }
    if (!f2 && len >= 3 && c[len - 3] == 'i' && c[len - 2] == 'z' && c[len - 1] == 'e')
    {
        f2 = 3;
        c[len - 3] = '\0';
        deal();
        return;
    }
    if (!f2 && len >= 1 && c[len - 1] == 's')
    {
        f2 = 4;
        c[len - 1] = '\0';
        deal();
        return;
    }
    if (!f2 && len >= 4 && c[len - 4] == 't' && c[len - 3] == 'i' && c[len - 2] == 'o' && c[len - 1] == 'n')
    {
        f2 = 5;
        c[len - 4] = '\0';
        deal();
        return;
    }
    return;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", c);
        f1 = f2 = 0;
        deal();
        if (f1 == 1)printf("against ");
        else if (f1 == 2)printf("after ");
        else if (f1 == 3)printf("before ");
        else if (f1 == 5)printf("not ");
        if (f2 == 1)printf("one who ");
        if (f2 == 2)printf("to actively ");
        if (f2 == 3)printf("change into ");
        if (f2 == 4)printf("multiple instances of ");
        if (f2 == 5)printf("the process of ");
        printf("%s", c);
        if (f2 == 1)printf("s");
        if (f2 == 5)printf("ing");
        if (f1 == 4)printf(" again");
        printf("\n");
    }
    return 0;
}
