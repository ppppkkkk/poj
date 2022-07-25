#include<iostream>
using namespace std;
/*

会员将赌注押在两个最终得分的总和上，或者押在两个得分之间的绝对差上。
给定每种投注的中奖号码，推断出最终得分
*/
int main() {
    int a, b, n, c, d;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        if ((a + b) % 2 == 1 || a < b) {
            printf("impossible\n");
            continue;
        }
        c = (a + b) / 2;
        d = (a - b) / 2;
        printf("%d %d\n", c, d);
    }
    return 0;
}
