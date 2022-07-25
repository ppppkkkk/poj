//找到满足i*i*i+j*(j+1)*(j+2)/6形式且小于等于n的最大值。
 #include<cstdio>
 #include<algorithm>
 #include<cstring>
 using namespace std;
 const int N=160000;
 bool mark[160000];
 int main()
 {
     memset(mark,false,sizeof(mark));
     for(int x=0;;x++)
     {
         int t=x*x*x;
         if(t>=N)
             break;
         mark[t]=true;
         for(int y=0;;y++)
         {
             int s=t+y*(y+1)*(y+2)/6;
             if(s>=N)
                 break;
             mark[s]=true;
         }
     }
     int n;
     while(scanf("%d",&n),n)
     {
         while(!mark[n])
             n--;
         printf("%d\n",n);
     }
     return 0;
 }
