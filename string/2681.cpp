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
    char a[50], b[50];
    int sa[50], sb[50];
    int n, Case, lena, lenb, ans;
    scanf("%d", &n);
    getchar();
    for (Case = 1;Case <= n;Case++) {
        gets_s(a);
        gets_s(b);
        lena = strlen(a);
        lenb = strlen(b);
        memset(sa, 0, sizeof(sa));
        memset(sb, 0, sizeof(sb));
        for (int i = 0;i < lena;i++)
            sa[a[i] - 'a']++;
        for (int i = 0;i < lenb;i++)
            sb[b[i] - 'a']++;
        ans = 0;
        for (int i = 0;i < 26;i++) {
            ans += abs(sa[i] - sb[i]);
        }
        printf("Case #%d:  %d\n", Case, ans);
    }
    return 0;
}
