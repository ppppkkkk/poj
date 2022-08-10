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
题意:算ACM出线名额,3种情况得名额:1、学校有队伍解题大于等于m。2、世界总决赛前20名学校。3、举办过比赛的学校

*/

int ans[105];
bool mark[105];
int main()
{
     int n, m, num, ca = 0;
     while (cin>>n>>m>>num,n,m,num)
     {
        for (int i = 0;i < n;i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            ans[a] = b + c;
        }
        memset(mark, 0, sizeof(mark));
        for (int i = 0;i < m;i++)
        {
             int a, b;
             cin >> a >> b;
             if (mark[a] || b < num)
                continue;
            mark[a] = true;
            ans[a]++;
        }
         int res = 0;
         for (int i = 1;i <= n;i++)
             res += ans[i];
        printf("Case %d: %d\n", ++ca, res);
     }
    return 0;

}
