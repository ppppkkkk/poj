#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
/*
一群牛排成一排，牛a 向右看能比他身高小的牛，直到一头身高比牛a高的牛挡住牛a的视野，
求牛0 到 牛n-1 中每头牛能看到其他牛的总数
单调栈
*/

int a[80001];
stack<int> st;
long long ans = 0;
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = 1000000000;
    for (int i = 0; i <= n; i++) 
    {
        while (!st.empty() && a[st.top()] <= a[i])//被挡住就出栈
        {
            ans += (i - st.top()-1);
            st.pop();
        }
        st.push(i);
    }
    cout << ans;
    return 0;
}
