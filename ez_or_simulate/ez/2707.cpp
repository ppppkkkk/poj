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


int main()
{
    int a, b, c, d;
    while (cin >> a >> b >> c >> d)
    {
        if (a+b+c+d==0)
            break;

        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);
        if (a <= c && b <= d)
        {
            cout << 100 << "%" << endl;
        }
        else
        {
            cout << min(int(double(c) / double(a) * 100), int(double(d) / double(b) * 100));
            cout << "%" << endl;
        }
    }
}
