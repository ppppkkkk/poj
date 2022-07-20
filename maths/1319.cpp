#include<iostream>
#include<math.h>
/*
poj 1319
给出一个容器的尺寸  a * b，在这个容器里装直径是单位长度的管子，
有两种装的办法，一种是题目里面给的图 a，图 b，另一种是图 c，图 d，问最多可以装多少个管子
*/
using namespace std;
const double P=sqrt(3.0)/2.0;
const double eps=1e-8;
int main()
{
	int max1,max2,max3,max,t;
	double a,b;
	while(cin>>a>>b)
	{
		max1=floor(a)*floor(b);
		max2=floor(a);
		t=1;
		while(1)
		{
			t++;
			if(b-(t-1)*P-1<eps)
				break;
			if(t%2==0)
		    	max2+=floor(a-0.5);
			else max2+=floor(a);
		}
		max3=floor(b);
		t=1;
		while(1)
		{
			t++;
			if(a-(t-1)*P-1<eps)
				break;
			if(t%2==0)
	    		max3+=floor(b-0.5);
			else
				max3+=floor(b);
		}
		max=max1;
		if(max<max2)
			max=max2;
		if(max<max3)
			max=max3;
		if(a-1.0<eps||b-1.0<eps)
			max=0;
		if(max==max1)
			cout<<max<<" "<<"grid"<<endl;
		else
			cout<<max<<" "<<"skew"<<endl;
	}
	return 0;
