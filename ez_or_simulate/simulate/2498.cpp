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
由问题的规则，确定 ‘？’的值是什么
*/




int factor[3] = { 9,3,7 };

int main() {
	int caseNum;
	cin >> caseNum;

	for (int i = 0;i < caseNum;i++) {
		string s;
		cin >> s;

		int sum = 0;
		int index;
		int num;
		for (int j = s.length() - 1;j >= 0;j--) {
			if (s[j] != '?') {
				sum += (s[j] - '0') * factor[(s.length() - j - 1) % 3];
			}
			else {
				index = s.length() - j - 1;
			}
		}

		for (int m = 0;m <= 9;m++) {
			if ((sum + m * factor[index % 3]) % 10 == 0) {
				num = m;
				break;
			}
		}

		cout << "Scenario #" << i + 1 << ":" << endl;
		for (int n = 0;n < s.length();n++) {
			if (s[n] != '?') {
				cout << s[n];
			}
			else {
				cout << num;
			}
		}

		cout << "\n" << endl;
	}

	return 0;
}
