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
输入n层数字三角形，求从第一层到最后一层最大权值和。
*/

int m[22][22];
int main()
{
    int n, begin;
    cin >> n >> begin;
    int num = begin;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j <= i;j++)
        {

            if (num % 10 == 0)
            {
                num = 1;
                m[j][i] = 1;
                num++;
            }
            else
            {
                m[j][i] = num % 10;
                num++;
            }
        }
    }
    int j = 0;
    while (j<n)
    {
        for (int i = 0;i < n;i++)
        {
            if (j <= i)
            {
                cout << m[j][i];
                if (i < n - 1)
                    cout << " ";
                else
                {
                    j++;
                    cout << endl;
                }
            }
            else
                cout << "  ";
        }
    }
    system("pause");
    return 0;
}
