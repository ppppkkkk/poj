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
如果一个数他的质数因子中只含有2,3,5,7其中的一个 或多个，就称为丑数，求n以内的丑数
 本题要求写出前5482个仅能被2，3，5, 7 整除的数。
*/


int main()
{
    int a[5843], x1, x2, x4, x3;
    a[1] = 1;
    x1 = x2 = x3 = x4 = 1;
    for (int i = 1;i <= 5842; ) {  //要点
        a[++i] = min(min(a[x1] * 2, a[x2] * 3), min(a[x3] * 5, a[x4] * 7));
        if (a[i] == a[x1] * 2) x1++;
        if (a[i] == a[x2] * 3) x2++;
        if (a[i] == a[x3] * 5) x3++;
        if (a[i] == a[x4] * 7) x4++;
    }
    string s;
    sort(a + 1, a + 5841);
    int n;
    while (cin >> n && n)
    {

        if (n % 10 == 1 && n % 100 != 11)
            s = "st";
        else if (n % 10 == 2 && n % 100 != 12)
            s = "nd";
        else if (n % 10 == 3 && n % 100 != 13)
            s = "rd";
        else s = "th";

        cout << "The " << n << s << " humble number is " << a[n] << "." << endl;
    }
    return 0;

}
