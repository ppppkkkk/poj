#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
//快速排序
int main(){
    int n,d[10005];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&d[i]);
    sort(d,d+n);
    printf("%d\n",d[(n-1)/2]);
    return 0;
} 
