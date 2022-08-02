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


int main() {
    int col, data[30], ans[30][300], pos[300];
    char a[4][100];
    memset(data, 0, sizeof data);
    for (int i = 0;i < 4;i++) {
        gets_s(a[i]);
        for (int j = 0;j < strlen(a[i]);j++) {
            if (a[i][j] >= 'A' && a[i][j] <= 'Z') {
                data[a[i][j] - 'A']++;
            }
        }
    }
    col = 0;
    for (int i = 0;i < 26;i++) {
        if (data[i] > col) {
            col = data[i];
        }
    }
    for (int j = 1;j <= col;j++) {
        for (int i = 0;i < 26;i++) {
            if (data[i] >= j) {
                ans[i][j] = 1;
            }
            else {
                ans[i][j] = -1;
            }
        }
    }
    for (int j = col;j >= 1;j--) {
        for (int i = 26;i >= 0;i--) {
            if (data[i] >= j) {
                pos[j] = i;
                break;
            }
        }
    }
    for (int j = col;j >= 1;j--) {
        for (int i = 0;i < 26;i++) {
            if (i < pos[j]) {
                if (ans[i][j] == 1) {
                    printf("* ");
                }
                else if (ans[i][j] == -1) {
                    printf("  ");
                }
            }
            else if (i == pos[j]) {
                printf("*");
                printf("\n");
                break;
            }
        }
    }
    for (int i = 0;i < 25;i++) {
        printf("%c ", 'A' + i);
    }
    printf("Z\n");
    return 0;
}
