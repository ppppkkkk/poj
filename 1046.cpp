#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

struct Color
{
    float a;
    float b;
    float c;
};

int main()
{
    Color A[20];
    for (int i = 0;i < 16; i++)
        cin >> A[i].a >> A[i].b >> A[i].c;
    float x, y, z;
    while (cin >> x >> y >> z)             
    {
        if (x == -1 && y == -1 && z == -1)
            break;
        float min = 225 * 225 * 225;//记录最小值
        int j = 0;//指针记录位置
        int s;
        for (int i = 0;i < 16; i++)
        {
            s = (x - A[i].a) * (x - A[i].a) + (y - A[i].b) * (y - A[i].b) + (z - A[i].c) * (z - A[i].c);
            if (min > s)
            {
                min = s;
                j = i;
            }
        }
        cout << "(" << x << "," << y << "," << z << ")" << " maps to (" << A[j].a << "," << A[j].b << "," << A[j].c << ")" << endl;
    }
    return 0;
}

