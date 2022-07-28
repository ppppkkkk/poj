#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;

/*
输入n，输入n个整数对，即n个坐标点，问最多共线点数是多少。

*/


struct point{
    int x, y;
}point[201];     

int main()
{
    int n, ans, max;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &point[i].x, &point[i].y);

    ans = 2;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            max = 2;
            for (int k = j + 1; k < n; k++)
                if ((point[j].x - point[i].x) * (point[k].y - point[j].y) == (point[j].y - point[i].y) * (point[k].x - point[j].x))
                    max++;
            if (max > ans)
                ans = max;
        }

    printf("%d\n", ans);

    return 0;
}
