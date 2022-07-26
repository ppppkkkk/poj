#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,a1,b1,c1;
    int T,n;
    int i,j;
    scanf("%d",&T);
    for(j=1;j<=T;j++)
    {
        scanf("%d",&n);
        if(n/100==1)
        {
            a=n/25;
            a1=n-a*25;
            b=a1/10;
            b1=a1-b*10;
            c=b1/5;
            c1=b1-c*5;
            d=c1;
            printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",j,a,b,c,d);
        }
        else
        {
            a=n/25;
            a1=n-a*25;
            b=a1/10;
            b1=a1-b*10;
            c=b1/5;
            c1=b1-c*5;
            d=c1;
            printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",j,a,b,c,d);
        }
    }
    return 0;
}
