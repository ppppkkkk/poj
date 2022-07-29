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
求解将所有插排（outlets）连接到一起后，能够有多少插孔可供电器使用；
*/

int main()
{
    int n, k, temp;
    scanf("%d", &n);
    while (n--)
    {
        int sum = 0;
        scanf("%d", &k);
        for (int i = 0; i < k; i++)
        {
            scanf("%d",&temp);
            sum += temp;
        }
        sum = sum - k + 1;
        printf("%d\n", sum);
    }
    return 0;
}
