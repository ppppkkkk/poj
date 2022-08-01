#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
using namespace std;

/*
有n个牛栏，选m个放进牛，相当于一条线段上有 n 个点，选取 m 个点，
使得相邻点之间的最小距离值最大
二分枚举相邻两牛的间距，判断大于等于此间距下能否放进所有的牛
*/


int s[100001];
int n, c;
bool judge(int size) {//枚举间距size
	int cnt = 1;//cnt为1表示已经第一头牛放在s[0]牛栏中
	int last = 0;//s[0]
	for (int i = 1;i < n;i++) {
		if (s[i] - s[last] >= size)//间距大于等于size，表示可以再放进牛
		{
			cnt++;//牛+1
			last = i;
		}
	}
	return cnt >= c;//所有牛都放完了则true
}
int main() 
{
	scanf("%d%d", &n, &c);
	for (int i = 0;i < n;i++)
		scanf("%d", &s[i]);
	sort(s, s + n);
	int l = 0, r = s[n-1]-s[0];
	while (l < r) {
		int mid = (l + r) / 2;
		if (judge(mid)) 
			l = mid + 1;
		else 
			r = mid;
	}
	printf("%d\n", l - 1);
	return 0;
}


