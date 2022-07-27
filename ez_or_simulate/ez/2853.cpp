#include<iostream>
#include<cstring>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
    int count=0;
    int a,b;
    scanf("%d%d",&a,&b);
    int k=2;
    while(b-k*(k-1)/2>0)
    {
      if((b-k*(k-1)/2)%(k)==0)
      {
        count++;
      }
      k++;
    }
    printf("%d %d\n",i,count);
  }
  return 0;
}
