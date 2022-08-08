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
每天人都要摄入各种食物，然后每种食物，可能含有脂肪，蛋白质，盐，淀粉，酒精这些东西的一种或者几种。
然后求出每日从这些食物中从脂肪中摄取的卡路里的总数占每天摄入的所有卡路里总数的百分比。
注意要四舍五入输出。
*/

char st[100];
char unit;
double fat;
double total;

void input()
{
    int temp;
    char ch;
    sscanf(st, "%d%c", &temp, &ch);
    bool percent;
    int p = 0;
    int c = 0;
    if (ch == '%')
    {
        percent = true;
        p += temp;
    }
    else if (ch == 'g')
    {
        percent = false;
        c += temp * 9;
        fat += temp * 9;
    }
    else
    {
        percent = false;
        c += temp;
        fat += temp;
    }
    int f[4] =
    { 4 , 4 , 4 , 7 };
    for (int i = 0; i < 4; i++)
    {
        int a;
        scanf("%d%c", &a, &ch);
        if (ch == '%')
            p += a;
        else if (ch == 'g')
            c += a * f[i];
        else
            c += a;

    }
    total += c / (100.0 - p) * 100;
    if (percent)
        fat += c / (100.0 - p) * temp;
}

int main()
{
    while (scanf("%s", st), strcmp(st, "-"))
    {
        fat = 0;
        total = 0;
        do
        {
            input();
        } while (scanf("%s", st), strcmp(st, "-"));
        cout<<(int)(fat * 100 / total + 0.5 )<<"%"<<endl;
    }
    return 0;
}
