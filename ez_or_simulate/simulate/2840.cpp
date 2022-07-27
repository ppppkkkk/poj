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

int main() {
    int n;


    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int h, m;
        scanf("%d:%d", &h, &m);
        if (m == 0) {
            if (h == 12) {
                printf("24\n");
            }
            else {
                printf("%d\n", (12 + h) % 24);
            }
        }
        else {
            printf("0\n");
        }
    }
    return 0;
}

