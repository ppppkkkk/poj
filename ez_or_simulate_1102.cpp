#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
char map[300][300];



void Display(int n, int c, int s)
{
    int i, j;
    if (n != 1 && n != 4) {  //上横 
        for (j = c + 1; j < c + s + 1; j++)
            map[0][j] = '-';
    }
    if (n != 1 && n != 0 && n != 7) { //中横 
        for (j = c + 1; j < c + s + 1; j++)
            map[s + 1][j] = '-';
    }
    if (n != 1 && n != 4 && n != 7) {   //下横 
        for (j = c + 1; j < c + s + 1; j++)
            map[2 * s + 2][j] = '-';
    }
    if (n != 1 && n != 2 && n != 3 && n != 7) { //左上竖 
        for (i = 1; i < s + 1; i++) {
            map[i][c] = '|';
        }
    }
    if (n != 5 && n != 6) {    //右上竖 
        for (i = 1; i < s + 1; i++) {
            map[i][c + s + 1] = '|';
        }
    }
    if (n == 2 || n == 6 || n == 8 || n == 0) {  //左下竖
        for (i = s + 2; i < 2 * s + 2; i++) {
            map[i][c] = '|';
        }
    }
    if (n != 2) {  //右下竖
        for (i = s + 2; i < 2 * s + 2; i++) {
            map[i][c + s + 1] = '|';
        }
    }
}
int main()
{
    int s, i, j, len, c;
    char str[10];
    while (scanf("%d", &s)) {
        scanf("%s", str);
        if (s == 0 && strcmp(str, "0") == 0)
            break;
        len = strlen(str);
        memset(map, 0, sizeof(map));
        for (i = 0; i < 2 * s + 3; i++) {
            for (j = 0; j < len * (s + 3) - 1; j++)
                map[i][j] = ' ';
        }
        for (i = 0; i < len; i++) {
            Display(str[i] - '0', (s + 3) * i, s);
        }

        for (i = 0; i <= 2 * s + 2; i++)
            printf("%s\n", map[i]);
        printf("\n");
    }
}
