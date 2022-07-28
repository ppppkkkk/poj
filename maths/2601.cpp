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
题意： 公式ai = (ai-1 + ai+1)/2 - ci ，已知a0,an+1,和ci(i=1~~n),求a1

由ai = (ai-1 + ai+1)/2 - ci

2*ai=(ai-1+ai+1)/2-2*ci;


a1=((an+1+n*a0)-2n*(c1)+2*(n-1)*c2+++++…………2*1*cn)/（n+1）;

*/

int main()
{
    int n;
    cin >> n;
    double a0, an;
    double c;
    double sum = 0;
    scanf("%lf%lf", &a0, &an);
    sum += an + n * a0;
    for (int i = 0;i <n;i++)
    {
        scanf("%lf", &c);
        sum -= 2 * (n - i) * c;
    }
    printf("%.2lf", sum / (n + 1));
}
