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

int Map[30];

string fun(int sum);

int main()
{
    int T;
    Map['m' - 'a'] = 1000;
    Map['c' - 'a'] = 100;
    Map['x' - 'a'] = 10;
    Map['i' - 'a'] = 1;
    cin >> T;
    while (T--)
    {
        string s1;
        string s2;
        cin >> s1 >> s2;
        int sum1=0,sum2=0;
        for (int i = 0; i < s1.length(); ++i)
        {

            if (s1[i] >= '2' && s1[i] <= '9')
            {
                ++i;
                sum1 += (s1[i - 1] - '0') * Map[s1[i] - 'a'];
            }
            else
            {
                sum1 += Map[s1[i] - 'a'];
            }
        }
        for (int i = 0; i < s2.length(); ++i)
        {
            if (s2[i] >= '2' && s2[i] <= '9')
            {
                ++i;
                sum2 += (s2[i - 1] - '0') * Map[s2[i] - 'a'];
            }
            else
            {
                sum2 += Map[s2[i] - 'a'];
            }
        }
        int sum = sum1 + sum2;
        cout << fun(sum) << endl;
    }
}

string fun(int sum)
{
    string s;
    int m;
    int c;
    int x;
    int i;
    m = sum / 1000;
    sum %= 1000;
    c = sum / 100;
    sum %= 100;
    x = sum / 10;
    sum %= 10;
   i = sum;
    if (m)
    {
        if (m == 1)
        {
            s += 'm';
        }
        else
        {
            s += char(m + '0');
            s += 'm';
        }
    }
    if (c)
    {
        if (c == 1)
        {
            s += 'c';
        }
        else
        {
            s += char(c + '0');
            s += 'c';
        }
    }

    if (x)
    {
        if (x == 1)
        {
            s += 'x';
        }
        else
        {
            s += char(x + '0');
            s += 'x';
        }
    }

    if (i != 0)
    {
        if (i == 1)
        {
            s += 'i';
        }
        else
        {
            s += char(i+'0');
            s += 'i';
        }
    }
    return s;
}
