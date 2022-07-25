#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

/*
在已知的三个人里找到满足条件的输出出来，中间加空格。有多个就输出多个
*/

int main() {
    double v[3][3] = { 4.5,150,200, 6.0,300,500, 5.0,200,300 };
    string n[3] = { "Wide Receiver","Lineman","Quarterback" };
    double a, b, c;
    while (cin >> a >> b >> c && a + b + c) {
        bool flag = 0;
        for (int i = 0;i < 3;i++) {
            if (a <= v[i][0] && b >= v[i][1] && c >= v[i][2]) {
                cout << n[i] << " ";
                flag = 1;
            }
        }
        if (!flag) printf("No positions");
        printf("\n");
    }
    return 0;
}
