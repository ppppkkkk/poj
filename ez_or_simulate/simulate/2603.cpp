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
N行里每行两个数分别代表a的N-I位和b的N-i位的数字，
将a和b相加求值  
只需要输出N位  
就算最后进位到N+1位也不用输出

*/

char a[1000001];

int main()
{
    int n, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d%d", &a[i], &b);
        a[i] += b;
    }
    n--;
    for (int carry = 0; n >= 0; n--) {
        a[n] += carry;
        carry = a[n] / 10;
        a[n] %= 10;
        a[n] += '0';
    }

    puts(a);

    return 0;
}
