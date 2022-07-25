#include <cstdio>
#include <iostream>
using namespace std;

/*

poj 1313
给打印的纸张进行编号
模拟

*/


const int MAXN = 128;
struct Page {
	int front1, front2;
	int back1, back2;
}pages[MAXN];
int n;
void print(int x)
{
	if (x > n) printf(" Blank");
	else printf(" %d", x);
}

int main()
{
	while (scanf("%d", &n) == 1, n) {
		int num = n % 4 == 0 ? n / 4 : n / 4 + 1;
		printf("Printing order for %d pages:\n", n);
		int cnt = 0;
		for (int i = 0;i < num;++i) {
			pages[i].front2 = ++cnt;
			pages[i].back1 = ++cnt;
		}
		for (int i = num - 1;i >= 0;--i) {
			pages[i].back2 = ++cnt;
			pages[i].front1 = ++cnt;
		}
		for (int i = 0;i < num;++i) {
			printf("Sheet %d, front:", i + 1);
			print(pages[i].front1);
			printf(",");
			print(pages[i].front2);
			puts("");
			if (pages[i].back1 > n && pages[i].back2 > n)
				continue;
			printf("Sheet %d, back :", i + 1);
			print(pages[i].back1);
			printf(",");
			print(pages[i].back2);
			puts("");
		}
	}
	return 0;

}
