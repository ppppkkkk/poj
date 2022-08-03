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

const int INF = 0x3f3f3f3f;
/*
求单源到各点最短路径
*/


int n;
int m[101][101];
bool visited[101];
int d[101];//mincost[i]表示i到已知集合最小值
void dijkstra() {
    for (int i = 0;i < n;i++) {
        d[i] = INF;
        visited[i] = 0;
    }
    d[0] = 0;
    int ans = 0;
    for (int i = 0;i < n;i++) {
        int v = -1;
        for (int j = 0;j < n;j++) {
            if (!visited[j] && (v == -1 || d[j] < d[v])) {
                v = j;
            }
        }
        if (v == -1)
            break;
        visited[v] = 1;
        for (int u = 0;u < n;u++) {
            //d[u]=min(d[u],m[v][u]);//这里和djikstra算法有区别
            d[u] = min(d[u], d[v] + m[v][u]);
        }
    }
}
int cal(string s) {
    int ans = 0;
    for (int i = 0;i < s.length();i++) {
        ans = ans * 10 + s[i] - '0';
    }
    return ans;
}

int main() {
    cin >> n;
    string ch;
    memset(m, 0, sizeof(m));
    for (int i = 1;i < n;i++) {
        for (int j = 0;j < i;j++) {
            cin >> ch;
            if (ch == "x") {
                m[i][j] = INF;
                m[j][i] = INF;
            }
            else {
                int ans = cal(ch);
                m[i][j] = ans;
                m[j][i] = ans;
            }
        }
    }
    int ans = 0;
    dijkstra();
    for (int i = 1;i < n;i++) {
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
    return 0;
}
