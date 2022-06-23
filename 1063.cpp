 #include<stdio.h>
 #include<math.h>
 int main()
 {
     int d[30],n,c;
     scanf("%d",&n);
     while(n>0)
     {
         int ow=0,ew=0;
         scanf("%d",&c);
         for(int i=0;i<c;i++)
             scanf("%d",&d[i]);
         if(c%2==1)
             printf("YES\n");
         else
         {
             for(int i=0;i<c;i++)
             {
                 if(d[i]==0)
                 {
                     if(i%2==0)
                         ow++;
                     else
                         ew++;
                 }
             }
             if(abs(ow-ew)<2)
                 printf("YES\n");
             else
                 printf("NO\n");
         }
         n--;
     }
     return 0;
 }
