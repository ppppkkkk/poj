#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
/*
给定一个长为n的字符串（n<=1e6），对于下标i（2<=i<=n），如果子串s(1...i)是周期子串，输出其最大周期。
kmp算法next子串
*/

int Next[1000001];
char s[1000001];

void getNext(char str[]) {
    int len = strlen(str + 1);
    Next[1] = 0;
    for (int k = 0, q = 2; q <= len; ++q) {
        while (k > 0 && str[k + 1] != str[q])
            k = Next[k];
        if (str[k + 1] == str[q])
            k++;
        Next[q] = k;
    }
}


int main() {
    int T;
    int Case = 0;
    while (cin >> T && T) {
        cin >> (s + 1);
        getNext(s);
        cout << "Test case #" << ++Case << endl;
        for (int i = 2; i <= T; ++i) {
            int temp = i - Next[i];
            if (temp != i && i % temp == 0) {
                cout << i << ' ' << (i / temp) << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
