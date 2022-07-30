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

int fx[1001];
int main()
{
    int a, b, c, d, e, f, g, h, i;
    int test;
    cin >> test;
    while (test--)
    {
        cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
        fx[0] = a;
        fx[1] = b;
        fx[2] = c;
        for (int j = 3;j <= i;j++)
        {

            if (j % 2 == 1)
            {
                fx[j] = (d * fx[j - 1] + e * fx[j - 2] - f * fx[j - 3]) % g;
                if (fx[j] < 0)
                    fx[j] += g;

            }
            else
            {
                fx[j] = (f * fx[j - 1] - d * fx[j - 2] + e * fx[j - 3]) % h;
                if (fx[j] < 0)
                    fx[j] += h;

            }
        }
        cout << fx[i] << endl;
    }
}
