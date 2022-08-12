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
给定涂料，每套涂料含有3-12种不同的颜色（开始时候给定选用的颜料套的颜色数目），
且一套涂料中每种颜色均有50ml。且一套涂料中的任意三种不同的颜色各X ml混合都可以获得 灰色颜料 X ml。
  现在给定需要的各个颜色的数量（这些颜色都属于同一套颜料），以及需要的灰色颜色的数量。
求最少需要多少套颜料才能获得这些颜色。
greedy
*/

#define MAX_NUM 13
int paint[MAX_NUM];
int bottle[MAX_NUM];
bool cmp(const int a, const int b) {
    return a > b;
}

int solve(int n, int gray) {
    sort(paint, paint + n, cmp);
    int min_bottle = paint[0] / 50 + int(paint[0] % 50 != 0);
    int result = min_bottle;
    if (gray <= 0) {
        return result;
    }
    for (int i = 0; i < n; i++) {
        paint[i] = min_bottle * 50 - paint[i];
    }
    sort(paint, paint + n, cmp);

    while (gray) 
    {
        if (paint[2] == 0) 
        {
            for (int i = 0; i < n; i++) {  //如果还有剩余的颜色的数目小于三种，则增加一套颜料
                paint[i] += 50;
            }
            result++;
        }
        paint[0] --;   //每次只减少 1ml的量
        paint[1] --;
        paint[2] --;
        gray--;
        //sort(paint, paint + n, cmp);
    }

    return result;
}

int main() {
    int n, gray;
    while (cin >> n, n) 
    {
        for (int i = 0; i < n; i++) 
        {
            cin >> paint[i];
        }
        cin >> gray;
        cout << solve(n, gray) << endl;
    }

    return 0;
}
