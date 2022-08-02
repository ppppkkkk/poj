#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
using namespace std;

bool judge(int n) {
    int s[3];
    int flag = 0;
    int tmp = n;
    s[0] = 0;
    while (tmp > 0) {
        s[0] += tmp % 10;
        tmp /= 10;
    }
    s[1] = 0;
    tmp = n;
    while (tmp > 0) {
        s[1] += tmp % 16;
        tmp /= 16;
    }
    tmp = n;
    s[2] = 0;
    while (tmp > 0) {
        s[2] += tmp % 12;
        tmp /= 12;
    }
    if (s[0] == s[1] && s[1] == s[2])
        flag = 1;
    return flag;
}
int main() {
    for (int i = 2992;i < 10000;i++) {
        if (judge(i))
            printf("%d\n", i);
    }
    return 0;
}
