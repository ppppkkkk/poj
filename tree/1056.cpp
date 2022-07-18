/*
poj 1056
一串编码是另一串的前缀
霍夫曼树
*/

# include <stdio.h>
# include <string.h>
  int main()
  {
      int i;
      int k;//指针
      int n;
      int t=1;//用例编号
      int flag=0;
      int a[2500];//打表
      char s[15];
      while(gets(s))
      {
          if(s[0]=='9')
          {
              if(flag==1)
                printf("Set %d is not immediately decodable\n",t++);
              else
                printf("Set %d is immediately decodable\n",t++);
              flag=0;
              memset(a,0,sizeof(a));
              continue;
          }
          n=strlen(s);
          for(i=0,k=1;i<n;i++)
          {
              if(s[i]=='0')
                k=2*k;
              else
                k=2*k+1;
              if(a[k]==1)
                flag=1;
          }
          a[k]=1;
      }
      return 0;
  }
