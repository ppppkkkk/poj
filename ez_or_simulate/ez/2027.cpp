#include<iostream>
using namespace std;
int main(){
    int a,b,n;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        if(a<b)printf("NO BRAINS\n");
        else printf("MMM BRAINS\n");
    }
    return 0;
}
