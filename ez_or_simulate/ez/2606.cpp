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


*/



int main() 
{
    int n, m;
    scanf("%d%d", &n, &m);
    
        if (n > m) 
            swap(n, m);
        int res = 0;
        if (n == 1) {
            res = (m + 1) / 2;
        }
        else if (n % 3 == 0 || m % 3 == 0) {
            res = 2;
        }
        else
            res = 1;
        printf("%d\n", res);
    
    return 0;
}
