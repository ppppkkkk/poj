#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
按题意重定义除法
*/

int main()
{
    int s;
    while (cin >> s)
    {
        int n = 1, t = 1;
        while (n)//除法
        {
            while (n < s)
            {
                n = n * 10 + 1;
                t++;
            }
            n = n % s;
        }
        cout << t << endl;
    }
    return 0;
}
