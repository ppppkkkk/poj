#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
给出生产酸奶的当前星期的成本和当前星期酸奶的需求量，问如何用最少的成本满足需求量。
（可以提前生产酸奶，然后把酸奶贮藏到仓库中，仓库一个星期收取费用s元），注意上面的费用都是单位酸奶的费用。

*/



int C[10050];//生产
int Y[10050];//交付
int S;

int main() {
    int mincost, N;
    long long int cost = 0;
    scanf("%d%d", &N, &S);//N周，S美分固定存储费用
    for (int i = 1;i <= N;i++) {
        scanf("%d%d", &C[i], &Y[i]);
    }

    mincost = C[1];
    cost = Y[1] * mincost;

    for (int i = 2;i <= N;i++) {
        mincost = min(C[i], mincost + S);
        cost += Y[i] * mincost;
    }

    printf("%lld\n", cost);
}
