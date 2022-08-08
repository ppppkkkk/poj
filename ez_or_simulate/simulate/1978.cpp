#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
/*
一叠卡片从上到下编号一次为 n, n-1, ..., 3, 2, 1，每次从这一叠卡片中抽出若干张放到最上面（如图），经过若干次这样的操作后，问最顶层的卡片的编号是多少。
栈模拟
*/

stack<int>s1, s2, s3;
void clear(stack<int> s)
{
	while (s.size())
		s.pop();
}

int main()
{

	int n, r, p, c;
	while (cin >>n >>r , n , r) {
		clear(s1);
		clear(s2);
		clear(s3);
		for (int i = 1;i <= n;i++)
			s1.push(i);
		for (int i = 0;i < r;i++) {
			cin >> p >> c;
			for (int j = 1;j < p;j++) {
				s2.push(s1.top());
				s1.pop();
			}
			for (int j = 1;j <= c;j++) {
				s3.push(s1.top());
				s1.pop();
			}
			for (int j = 1;j < p;j++) {
				s1.push(s2.top());
				s2.pop();
			}
			for (int j = 1;j <= c;j++) {
				s1.push(s3.top());
				s3.pop();
			}
		}

		printf("%d\n", s1.top());
	}
	return 0;
}
