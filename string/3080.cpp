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
在所给的字符串中找到公共的最长连续子串，长度相同则输出字典序小的
*/



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[11];
        string str = "no significant commonalities";
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        for (int i = 3; i <= 60; i++) {
            for (int j = 0; j <= 60 - i; j++) {
                string sub = s[1].substr(j, i);
                bool flag = true;
                for (int k = 2; k <= n; k++) {
                    if (s[k].find(sub) == -1) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    continue;
                }
                else {
                    if (str == "no significant commonalities") {
                        str = sub;
                    }
                    else if (str.size() < sub.size()) {
                        str = sub;
                    }
                    else if (str.size() == sub.size()) {
                        str = min(str, sub);
                    }
                }
            }
        }
        cout << str << '\n';
    }

    return 0;
}
