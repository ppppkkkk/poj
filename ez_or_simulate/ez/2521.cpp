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
    int m, c, p, n, sum;
    while (cin >> n >> m >> p >> c,m,c,p,n)
    {
        sum = p + n - m;
        cout << sum << endl;

    }
    return 0;
}
