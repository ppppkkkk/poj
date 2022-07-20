#include<iostream>
using namespace std;

/*

求Cnm
组合数公式。C(n,m)=C(n-1,m-1)+C(n-1,m)

*/


double c[110][110];

void init() {
    for (int i = 1; i <= 109; ++i)
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i)
                c[j][i] = 1;
            else
                c[j][i] = (c[j][i - 1] + c[j - 1][i - 1]);
        }
}

int main() {
    init();
    int n, x, y;
    while (cin >> x >> y) {
        if (x == 0 && y == 0) break;
        printf("%d%s%d%s%.0f%s\n", x, " things taken ", y, " at a time is ", c[y][x], " exactly.");
    }
    return 0;

}
