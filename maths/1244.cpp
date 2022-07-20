#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

/*
* poj 1244
给定一串字符串，按杨辉三角一次从上到下，从左到右摆放，
每个字符最多出现3次。问那些字符构成了一个等边三角形。将其输出之，如没有输出loser。


将第一个点设置成（10000,10000）
其后的点是没下降一层 y 要减去3，x减去根号3
*/
using namespace std;


#define eps 1e-7
#define ghs 1.7320508075

struct line {
    int num;
    double x[3], y[3];
}p[27];

bool judge(line& q) {
    double ans = (q.x[0] - q.x[1]) * (q.x[0] - q.x[1]) + (q.y[0] - q.y[1]) * (q.y[0] - q.y[1]);
    for (int i = 1; i < 3; i++) {
        if (fabs(ans - ((q.x[i] - q.x[(i + 1) % 3]) * (q.x[i] - q.x[(i + 1) % 3]) + (q.y[i] - q.y[(i + 1) % 3]) * (q.y[i] - q.y[(i + 1) % 3]))) > eps)return 0;
    }
    return 1;
}

int main() {

    int n, i, j;
    double t, a, b;
    char c;
    while (scanf("%d", &n), n) {
        for (i = 0; i < 27; i++) {
            p[i].num = 0;
        }
        a = 10000.0;
        b = 10000.0;
        getchar();
        for (i = 1; i <= n; i++) {
            t = a;
            for (j = 1; j <= i; j++) {
                c = getchar();
                p[c - 'a'].x[p[c - 'a'].num] = t;
                p[c - 'a'].y[p[c - 'a'].num] = b;
                p[c - 'a'].num++;
                t = t + 2 * ghs;
            }
            a = a - ghs;
            b = b - 3.0;
        }

        int flag = 0;
        for (i = 0; i < 26; i++) {
            if (p[i].num != 3)continue;
            if (judge(p[i])) { printf("%c", 'a' + i);flag = 1; }
        }
        if (!flag) {
            printf("LOOOOOOOOSER!");
        }
        putchar('\n');
    }
    return 0;
}
