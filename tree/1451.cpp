#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

const int maxn = 1e6 + 10;
int trie[maxn][26];
int sum[maxn];
map<string, int> map1;
map<string, string> map2;
int al_int[30];//将字母转变为手机上的键位
int tot;
/*

模拟手机输入法，先给你一个用户的词库，即每个单词出现的次数，
这个时候再按照九键输入法给你一个数字序列，问你在输入这个序列的过程中，出现的字符串顺序，
也就是对于你在手机上逐渐按出这个数字序列过程中的每个数字序列，智能的给出一个最有可能，频率最大的字符串。

对于每个数字序列，我们都可以用一个string去映射，
这样我们可以用一个map来保存每个数字序列对应的最有可能出现的字符串，
然后在插入的过程中，对于每一个前缀都更新一下这个前缀对应的map，最后查询的时候就可以直接输出了。

*/
void init() {
	for (int i = 0; i <= 17; ++i)
		al_int[i] = i / 3 + 2;
	al_int[18] = 7;
	for (int i = 19; i < 25; ++i)
		al_int[i] = (i - 1) / 3 + 2;
	al_int[25] = 9;
}

void insert(char* s, int num) {
	int len = strlen(s);
	int rt = 0;
	string t_int = "", t_al = "";//t_int是当前的前缀字符串对应的手机键位  t_al是当前的前缀字符串
	for (int i = 0; i < len; ++i) {
		int id = s[i] - 'a';
		t_int += al_int[id] + '0';
		t_al += id + 'a';
		if (trie[rt][id] == 0)
			trie[rt][id] = ++tot;
		rt = trie[rt][id];
		sum[rt] += num;
		if (sum[rt] > map1[t_int]) {//相同的手机键位数字下 当前字符串频率更大，更新
			map1[t_int] = sum[rt];//存字符串出现的频率
			map2[t_int] = t_al;//存字符串
		}
	}
}
int t, n, num;
char s[110];
int main() {
	int cnt = 1;
	init();
	for (scanf("%d", &t); t; --t) {
		map1.clear();
		map2.clear();
		scanf("%d", &n);
		tot = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s %d", s, &num);
			insert(s, num);
		}
		scanf("%d", &n);
		printf("Scenario #%d:\n", cnt++);
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			int len = strlen(s);
			string temp = "";
			for (int j = 0; j < len - 1; ++j) {
				temp += s[j];
				if (!map2.count(temp))
					printf("MANUALLY\n");
				else
					printf("%s\n", map2[temp].c_str());
			}
			printf("\n");
		}
		printf("\n");
		for (int i = 0; i <= tot; ++i) {
			sum[i] = 0;
			for (int j = 0; j < 26; ++j)
				trie[i][j] = 0;
		}
	}
}
