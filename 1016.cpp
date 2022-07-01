#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void R(char n[85],char t[85])
{
    int i,j;  
    int time[10]={0};    
    for(i=0;n[i];i++)  
        time[ n[i]-'0' ]++;  

    for(i=0,j=0;i<10;i++)  
    {  
        if(time[i])  
        {  
            if(time[i]<10)    
            {  
                t[j++]=time[i]+'0';  
                t[j++]=i+'0';  
            }  
            else     
            {  
                t[j++]=time[i]/10+'0';  
                t[j++]=time[i]%10+'0';  
                t[j++]=i+'0';  
            }  
        }  
    }  
    t[j]='\0';  

    return;
}

int main()
{
  int i,j;
  int flag1,flag2,flag3;
  char n[16][85];
  while(scanf("%s",n[0])&&(n[0][0]!='-'))
  {
    flag1=flag2=flag3=0;
    for(i=1;i<=15;i++)
    {
      R(n[i-1],n[i]);
    }
    if(!strcmp(n[0],n[1]))
    {
      flag1=1;
    }
    if(!flag1)
    {
      for(i=1;i<15;i++)
      {
        if(!strcmp(n[i],n[i+1]))
        {
          flag2=i;
          break;
        }
      }
      if(!flag2)
      {
        for(j=1;j<=15;j++)
        {
          for(i=0;i<=j-2;i++)
          {
            if(!strcmp(n[i],n[j]))
            {
              flag3=j-i;
              break;
            }
          }
          if(flag3)
             break;
        }
      }
    }
    if(flag1)
      printf("%s is self-inventorying\n",n);
    else if(flag2)
      printf("%s is self-inventorying after %d steps\n",n,flag2);
    else if(flag3)
      printf("%s enters an inventory loop of length %d\n",n,flag3);
    else
      printf("%s can not be classified after 15 iterations\n",n);    
  }  
  return 0; 
}
