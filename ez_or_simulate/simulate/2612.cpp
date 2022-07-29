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
输入一个n，然后输入两个n*n矩阵，一个代表雷的矩阵，一个代表走过的的矩阵。然后输出结果矩阵、
结果矩阵分两种情况，一个是没有踩到雷的，一个是踩到雷的，踩到雷的要把雷都显示出来。

*/

char Map[10][10];
char Visited[10][10];
char temp;

int main() {
    int n;
    scanf("%d", &n);
    temp = '.';
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++)
            cin >> Map[i][j];
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> Visited[i][j];
            if (Visited[i][j] == 'x' && Map[i][j] == '*')
                temp = '*';
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (Visited[i][j] == 'x' && Map[i][j] == '.') {
                int num = 0;
                for (int x = -1;x <= 1;x++) {
                    for (int y = -1;y <= 1;y++) {
                        int a = x + i;
                        int b = y + j;
                        if (a >= 0 && a < n && b >= 0 && b < n && Map[a][b] == '*')
                            num++;
                    }
                }
                printf("%d", num);
            }
            else if (Visited[i][j] == '.' || Map[i][j] == '*') {
                if (Map[i][j] == '*')
                    printf("%c", temp);
                else printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}
