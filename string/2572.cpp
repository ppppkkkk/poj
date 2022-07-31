#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;
/*
就是这个数反转过来相加若相等刚输出true,否则false
*/



int Reverse(string s)
{
    int a = 0;
    for (int i = s.length() - 1;i >= 0;i--)
        a = a * 10 + s[i] - '0';
    return a;
}
int main()
{
    string s, s1, s2, s3;
    while (cin >> s)
    {
        if (s == "0+0=0")
        {
            cout << "True" << endl;
            break;
        }
        int p1 = s.find("+");
        int p2 = s.find("=");
        s1 = s.substr(0, p1);   //substr(开始位置，长度）中的字符串
        s2 = s.substr(p1 + 1, p2 - p1 - 1);
        s3 = s.substr(p2 + 1, s.length() - 1 - p2);  //因第一个位置标号为0
        if (Reverse(s1) + Reverse(s2) == Reverse(s3)) cout << "True" << endl;
        else cout << "False" << endl;
    }
    return 0;
}
