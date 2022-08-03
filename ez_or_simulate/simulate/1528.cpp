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
/*

*/
int Data[101];
int ans[101];

int main() {
    int cnt = 0, temp ;
    while (cin>>Data[cnt], Data[cnt]!=0) {
        temp = 0;
        for (int i = 1;i <= Data[cnt] / 2;i++) {
            if (Data[cnt] % i == 0) {
                temp += i;
            }
        }
        if (temp == Data[cnt]) {
            ans[cnt] = 0;
        }
        if (temp < Data[cnt]) {
            ans[cnt] = -1;
        }
        if (temp > Data[cnt]) {
            ans[cnt] = 1;
        }
        cnt++;
    }
    printf("PERFECTION OUTPUT\n");
    for (int i = 0;i < cnt;i++) {
        printf("%5d  ", Data[i]);
        if (ans[i] == 0)
            printf("PERFECT\n");
        if (ans[i] == -1)
            printf("DEFICIENT\n");
        if (ans[i] == 1)
            printf("ABUNDANT\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
