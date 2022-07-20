#include<stdio.h>
#include<algorithm> 
#include<string>
#include<string.h>
using namespace std;

/*
poj 1226
给出n个字符串，找出一个最长的串s，使s或者s的反串满足同时是这n个串的子串。
对于样例，第一组ABCD   BCDFF  BRCD最长的串就是CD，第二组rose  orchid最长的子串就是ro
*/

char s[105][105];
int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);

		int min = 0;
		for (int i = 0;i < n;i++) {
			scanf("%s", s[i]);
			if (strlen(s[i]) < strlen(s[min])) {
				min = i;
			}
		}
		char s1[105];
		char s2[105];
		int max = 0;//统计数目

		for (int i = strlen(s[min]);i >= 1;i--) {//长度
			int flag = 1;
			for (int j = 0;j < strlen(s[min]) - i + 1;j++) {//起始位置 
				int k, l;
				for (k = j, l = 0;k < i + j;k++) s2[l++] = s[min][k];
				s2[l] = '\0';
				
				strcpy(s1, s2);//正 
				reverse(s2, s2 + i);//反
				flag = 1;
				for (k = 0;k < n;k++) {
					if (k == min) continue;
					if (strstr(s[k], s1) == NULL && (strstr(s[k], s2) == NULL)) {
						flag = 0;
						break;
					}
				}
				if (flag == 1 && max < i) {
					max = i;
					break;
				}
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
