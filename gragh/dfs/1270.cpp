#include<iostream>
#include<string.h>
#include<string> 
using namespace std;

/*
poj 1270
构建一个有向无环图，输出其所有的拓扑排序可能，并且按照字典序输出拓扑排序。
*/

const int maxn = 30;
int map[maxn][maxn], book[maxn], topo[maxn], in[maxn], n;//n个顶点   book:标记是否 
void dfs(int t) {//t:topo中数的个数. 
	if (t == n) {//结束条件 
		for (int i = 0;i < n; i++) {
			cout << char(topo[i] + 'a' - 1);
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= 26; i++) { //因为输入的字符不一定是按照给的个数从前往后的那些字母还可能是乱序的字符.所以每一个都应该进行遍历. 
		if (!in[i] && book[i]) {//如果该点存在,且入度为0 
			topo[t] = i;//将其加入拓扑序列 
			book[i] = 0;//在图中删除该点 ,下次就不能使用该点了. 
			for (int j = 1; j <= 26; j++) {
				if (map[i][j]) {
					in[j]--;
				}
			}
			dfs(t + 1);//进行下一轮
			//进行回溯,因为此刻还可能有其他的点满足条件. 
			book[i] = 1;
			for (int j = 1; j <= 26; j++) {
				if (map[i][j]) {
					in[j]++;
				}
			}
		}
	}

}
int main()
{
	string str, str2;
	while (getline(cin, str)) {
		memset(map, 0, sizeof(map));
		memset(book, 0, sizeof(book));
		memset(topo, 0, sizeof(topo));
		memset(in, 0, sizeof(in));
		n = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ' ') {
				n++;
				book[str[i] - 'a' + 1] = 1;
			}
		}
		getline(cin, str2);
		for (int i = 0; i < str2.size(); i = i + 2) {
			char ch1 = str2[i];
			i += 2;
			char ch2 = str2[i];
			map[ch1 - 'a' + 1][ch2 - 'a' + 1] = 1;
			in[ch2 - 'a' + 1]++;
		}
		dfs(0);
		cout << endl;
	}

	return 0;
}
