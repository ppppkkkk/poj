#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
题目大意：利用移位加密算法加密字符串
poj 1298
*/



int main()
{
    string s;
    while (getline(cin, s),(s != "ENDOFINPUT"))
    {
        getline(cin, s);
        int len = s.length();
        for (int i = 0;i < len;i++)
        {
            if (s[i] < 'A' || s[i]>'Z')
                continue;
            s[i] -= 5;
            if (s[i] < 'A')
                s[i] += 26;
        }
        cout << s << endl;
        getline(cin, s);
    }
    return 0;
}

