#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
using namespace std;
/*

*/

int func(int m, int n)
{
    if (m == 0 || n == 1)
        return 1;
    if (m < n) 
        return func(m, m);
    else
        return func(m, n - 1) + func(m - n, n);//至少有一个空盘子和一个空盘子都没有 
}

int main()
{
    int t, m, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d%d", &m, &n);
        printf("%d\n", func(m, n));
    }

}
