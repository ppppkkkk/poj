#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
/*
分数在平均分以上
*/
int main()
{
    int c, n, count;
    int num[1010], sum;
    double avg=0.0;

    scanf("%d", &c);
    for (int i = 0;i < c;i++)
    {
        scanf("%d", &n);
        sum = 0;
        for (int j = 0;j < n;j++)
        {
            scanf("%d", &num[j]);
            sum = sum + num[j];
        }
        avg = sum * 1.0 / n;
        count = 0;
        for (int j = 0;j < n;j++)
        {
            if (num[j] > avg)
            {
                count++;
            }
        }
        printf("%.3lf%%", count * 100 * 1.0 / n);
        printf("%\n");
    }
    return 0;
}
