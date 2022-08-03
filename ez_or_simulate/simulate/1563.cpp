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

int h, u, d, f, t;
double now, speed;

int main()
{
    while (cin >> h >> u >> d >> f , h )
    {
        now = 0;
        t = 1;
        speed = u;
        while (1) 
        {
            now += speed;
            if (now > h)
            {
                cout << "success on day " << t << endl;
                break;
            }
            now -= d;
            if (now < 0)
            {
                cout << "failure on day " << t << endl;
                break;
            }
            t++;
            speed -= u * f / 100.0;
            if (speed < 0)
                speed = 0;
        }
    }
    return 0;
}
