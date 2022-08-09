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

*/


int main()
{
    char s[30];
    while (gets_s(s) && strcmp(s, "R0C0") != 0)
    {
        int m = 0, i=1;
        for (;s[i] != 'C';i++);
            s[i] = '\0';
        i++;
        for (;s[i] != '\0';i++)
            m = m * 10 + s[i] - '0';
        char ans[30];
        m--;
        for (i = 0;m >= 0;i++)
        {
            ans[i] = m % 26 + 'A';
            m = m / 26 - 1;
        }
        ans[i] = '\0';
        reverse(ans, ans + i);
        printf("%s%s\n", ans, s + 1);
    }
    return 0;
}
