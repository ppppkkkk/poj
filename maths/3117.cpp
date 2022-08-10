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
一场足球赛中，如果双方打成了平手，那么双方各得一分，否则，赢得一方的3分，输得一方不得分。输入比赛的局数t和各队的得分情况，求出结果为平局的数量。
可以设赢得局数为X，平局为Y，那么总得分sum = 3X+2Y;且X+Y=t；
解方程组得：Y = 3t-sum；

*/

int main()
{
    int n, t;
    string s;
    int num;
    int sum;
    while (cin>>n>>t,n,t)//scanf不能n,t一起？
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> s >> num;
            sum += num;
        }
        int ans = 3 * t - sum;
        printf("%d\n", ans);
    }
    return 0;
}
