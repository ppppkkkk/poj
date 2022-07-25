#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 15;
int s[maxn],t[maxn]; 

int main()
{
    int n;
    while(scanf("%d",&n) && n!=-1)
    {
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&s[i],&t[i]);
            sum+=s[i]*(t[i]-t[i-1]);
        }
        printf("%d miles\n",sum);
    }
}
