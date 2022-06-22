#include <cstdio>
#include <iostream>
#include <string>
#define M 40000
 
using namespace std;

bool ans[3][M];
 //打表，可用中国算法
int main()
{
    int p, e, i, d;
    int n=0;
 
    while(cin>>p>>e>>i>>d, p >= 0)
    {
        memset(ans, 0, sizeof(ans));
 
        p = p % 23;//得到在一个周期内高峰第几天
        e = e % 28;
        i = i % 33;
 
        for(int j = p; j < M; j += 23)
            ans[0][j]++;
 
        for(int j = e; j < M; j += 28)
            ans[1][j]++;
 
        for(int j = i; j < M; j += 33)
            ans[2][j]++;
 
 
        for(int j = d + 1; j < M; j++)
            if(ans[0][j] == 1 && ans[1][j] == 1 && ans[2][j] == 1 )
        {
            printf("Case %d: the next triple peak occurs in %d days.\n", ++n, j - d);
            break;
        }
    }

    return 0;
}
