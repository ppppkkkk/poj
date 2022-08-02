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

int  main()
{
    int n, e;
    int a, b;
    int length, width;
    double sum;
    while (cin >> n >> e)
    {
        length = 0;
        width = 0;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            length += a;
        }
        for (int i = 0; i < e - 1; i++)
        {
            cin >> b;
            width += b;
        }
        if (n == 1 && e == 1) cout << "0"<< endl;
        else
        {
            sum = sqrt(1.0*(length * length + width * width));
            cout << ceil(sum) << endl;;
        }
    }
}
