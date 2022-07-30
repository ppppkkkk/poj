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
    int n, k;
    while (cin>>n>>k)
    {
       int  res = n;
       while (n / k) 
       {
           res += n / k;
           n = n / k + n % k;
        }
        printf("%d\n", res);
    }
    return 0;
}
