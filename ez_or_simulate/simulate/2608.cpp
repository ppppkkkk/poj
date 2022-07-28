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

/*
用字母模拟数字，没有数字代表的则跳过，
有数则代表但是连续多组的只输出一个。

*/


int Alpha[26] = { 0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2 };
int main()
{
    string s;
    int b[100];
    int a[100];
    while (cin >> s)
    {
        int lens = s.size();
        for (int i = 0;i < lens;i++)
        {
            if (Alpha[s[i] - 'A'] == 0)
                b[i] = 0;
            else if (Alpha[s[i] - 'A'] == 1)
                b[i] = 1;
            else if (Alpha[s[i] - 'A'] == 2)
                b[i] = 2;
            else if (Alpha[s[i] - 'A'] == 3)
                b[i] = 3;
            else if (Alpha[s[i] - 'A'] == 4)
                b[i] = 4;
            else if (Alpha[s[i] - 'A'] == 5)
                b[i] = 5;
            else if (Alpha[s[i] - 'A'] == 6)
                b[i] = 6;
        }
        int count = 0;
        for (int i = 0; i < lens;i++)
        {
            if (b[i])
                if (i >= 1 && b[i] != b[i - 1] || !i)
                    a[count++] = b[i];
        }
        for(int i=0;i<count;i++)
            printf("%d", a[i]);
        printf("\n");
    }
    return 0;
}
