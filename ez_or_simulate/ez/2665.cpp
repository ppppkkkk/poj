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
    int l, m, result, start, end;
    while (cin >> l >> m, l || m) {
        result = l + 1;
        while (m--) {
            scanf("%d%d", &start, &end);
            result -= end - start + 1;
        }
        printf("%d\n", result);
    }
    return 0;
}
