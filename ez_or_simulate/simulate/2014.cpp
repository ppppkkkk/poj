#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
  给你几个小矩形，（依次给你他们的长和宽），把他们放在一个长为 max 宽没有限制的大矩形中，问放完这些小矩形所需要的最小矩形是几x几的？
  要求从左向右依次放，知道长度限制不能放下，然后在这一行下面接着从左向右放。

*/


int main() {
	int x, y, m, now, w, h, last;
	while (scanf("%d", &m), m) {
		w = h = last = now = 0;
		while (scanf("%d%d", &x, &y)) {
			if (x == -1 && y == -1) {
				printf("%d x %d\n", w, h);
				break;
			}
			if (now + x <= m) {//限制长度
				now += x;
				w = max(w, now);
				h = max(h, last + y);
			}
			else {//换行
				now = x;
				w = max(now, w);
				last = h;
				h = last + y;
			}
		}
	}
	return 0;
}
