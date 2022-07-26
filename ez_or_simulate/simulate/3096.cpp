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
给定一个字符串，如果这个字符串按照间隔 d 取字符对的过程中，对于相同的d没有相同字符对是相同的。 那么这个字符串就是 d-unique的。
而如果这个字符串对于每一个di都是 di-unqiue的话，这个字符串就满足surprising的。

*/



int main() {
    char s[80];

    while (cin >> s && s[0] != '*') {

        int len = strlen(s);
        if (len < 3) {
            cout << s << " is surprising.\n";
            continue;
        }
        bool v = true;
        for (int k = 1; k < len; k++) {
            map<string, bool> flag;

            for (int i = 0; i + k < len; i++)
            {
                char str[3] = { s[i] , s[i + k] , '\0' };
                if (flag[str]) {
                    v = false;
                    break;
                }
                flag[str] = true;
            }
        }
        if (v) cout << s << " is surprising.\n";
        else cout << s << " is NOT surprising.\n";
    }
}


