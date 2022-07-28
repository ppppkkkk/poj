#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;

/*
给定一串数字，数字没有重复，个数为2~10个。
求这些数字分为两份，组合成的两个数的差最小是多少
*/


int Count;//用来记录第二行输入数字的个数
char ch;//输入字符串
int a[10];//用来存储第二行输入

int multiple(int i, int j) {
	int x = 0;
	for (int k = i;k < j;k++) {
		x = x * 10;
		x += a[k];
	}
	return x;
}
void solve() {
	int result = 100000;
	int length = Count / 2;//得到第一个数字的长度
	do {
		if (a[0] == 0 || a[length] == 0) 
			continue;//0在第一位
		int x1 = multiple(0, length);
		int x2 = multiple(length, Count);
		result = min(abs(x2 - x1), result);

	} while (next_permutation(a, a + Count));//每次一个全排列，字典序
	if (Count == 2) {
		result = abs(a[1] - a[0]);
	}
	printf("%d\n", result);
}
int main() {
	int n;
	scanf("%d", &n);
	while(n--){
		Count = 0;
		do {
			scanf("%d", &a[Count]);
			Count++;
		} while ((ch = getchar()) != '\n');//当读入回车时，停止读入
		solve();
	}
	return 0;

}


