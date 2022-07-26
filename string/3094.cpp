#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

/*
poj 3094
*/

char a[256];
int sum;
int main()
{
    while (gets_s(a), strcmp(a, "#") != 0)
    {
        sum = 0;
        for (int i = 0;i < strlen(a);i++)
        {
            if (a[i] != ' ')
            {
                sum += (i + 1) * (a[i] - 'A' + 1);
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
