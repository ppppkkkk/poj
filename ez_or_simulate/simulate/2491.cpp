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
    int T, Case = 1;
    map<string, string > pre, next;
    cin >> T;
    while (T--) {
        pre.clear(); 
        next.clear();
        string s, e;
        int n;
        cin >> n;
        for (int i = 0;i < n - 1;i++) {
            cin >> s >> e;
            next[s] = e;
            pre[e] = s;
        }
        while (pre[s] != "") {
            s = pre[s];
        }
        cout << "Scenario #" << Case++ << ":" << endl;
        cout << s << endl;

        while (next[s] != "") {
            cout << next[s] << endl;
            s = next[s];
        }
        cout << endl;

    }
    return 0;

}
