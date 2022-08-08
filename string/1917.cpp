#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
#include <queue>
using namespace std;
/*
*/
char str[2][110];

int main()
{
    int n, mark[4];
    char x;
    scanf("%d%c", &n, &x);
    while (n--) {
        gets_s(str[0]);
        gets_s(str[1]);
        int len = strlen(str[0]);
        for (int i = 0, j = 0;i < len;i++) {
            if (str[0][i] == '<' || str[0][i] == '>') {    //mark用来记录下<>的位置。
                mark[j] = i;
                j++;
            }
            else {
                printf("%c", str[0][i]);   //如果没有括号的，就直接输出就可以。
            }
        }
        printf("\n");
        for (int i = 0;i < strlen(str[1]) - 3;i++)    //调换位置。
            printf("%c", str[1][i]);
        for (int i = mark[2] + 1;i < mark[3];i++)
            printf("%c", str[0][i]);
        for (int i = mark[1] + 1;i < mark[2];i++)
            printf("%c", str[0][i]);
        for (int i = mark[0] + 1;i < mark[1];i++)
            printf("%c", str[0][i]);
        for (int i = mark[3] + 1;i < len;i++)
            printf("%c", str[0][i]);
        printf("\n");
    }
    return 0;
}
