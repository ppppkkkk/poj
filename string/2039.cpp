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
加密重写
*/

int main() {
    char str[205][205], name[250];
    int n, m, i, j, k, flag;
    while (cin >> n , n) {
        cin >> name;
        j = i = m = 0;
        flag = 1;
        while (name[m]) {
            if (j < n && flag == 1) {
                str[i][j] = name[m];
                m++;
                j++;
            }
            else if (j == n) {
                j--;
                flag = 2;
                i++;
                str[i][j] = name[m];
                m++;j--;
            }
            else if (j >= 0 && flag == 2) {
                str[i][j] = name[m];
                m++;j--;
            }
            else if (j < 0) {
                j++;
                flag = 1;
                i++;
                str[i][j] = name[m];
                m++;
                j++;
            }
        }
        k = i;
        for (j = 0;j < n;j++) {
            for (i = 0;i <= k;i++) {
                cout << str[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
