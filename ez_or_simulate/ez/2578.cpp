#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;
int main() {
    int a[3], pos;
    for (int i = 0;i < 3;i++)
    {
        cin >> a[i];
    }
    int flag = 1;
    for (int i = 0;i < 3;i++) {
        if (a[i] <= 168) {
            flag = 0;
            pos = i;
            break;
        }
    }
    if (flag)
        printf("NO CRASH\n");
    else
        printf("CRASH %d\n", a[pos]);
    return 0;
}
