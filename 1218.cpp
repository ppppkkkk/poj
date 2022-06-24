//题意：喝第一杯酒，每隔0个门，操控门一次，喝第二杯酒，每隔1个门，操控门一次...
//统计开着的门的个数 
#include<stdio.h>
int main()
{
	int n,i,j,k,a,count,counter;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		counter=0; 
		scanf("%d",&a);
		for(k=1;k<=a;k++) //从第一个门开始统计， 
		{
			count=0;
			//喝了第j杯酒的时候是否能被j整除，如果被整除，说明第j个门被操控了 
			for(j=1;j<=a;j++) 
		 		if(k%j==0)
			 		count++;//统计被操控的次数，即被开关的次数 
			if(count%2!=0)
				counter++; //如果开关次数能被2整除，说明这个门是开着的 
		}  
		printf("%d\n",counter); 	 	
	}
	return 0;
} 
