#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

/*
给你一堆字符串，我们定义一个字符串可以被缩写成一个字符串（必须是原字符串的前缀），
问你每个字符串能辨识的前缀是什么
*/

struct tree
{
	int sum;            //前缀数
	tree* next[26];		//下一个位置可能的26个字母
}*root;                 


void insert(const char* s)//建立树
{
	tree* p = root;
	while (*s != '\0')
	{
		if (p->next[*s - 'a'] == NULL)
		{
			p->next[*s - 'a'] = new tree;
			p = p->next[*s - 'a'];
			p->sum = 1;
			for (int i = 0;i < 26;i++)
				p->next[i] = NULL;
		}
		else
		{
			p = p->next[*s - 'a'];
			p->sum++;
		}
		s++;
	}
}
void Search(const char* s)//查询
{
	tree* p = root;
	while (*s != '\0')
	{
		if (p->next[*s - 'a'] == NULL)   //单词不存在
			return;
		p = p->next[*s - 'a'];    
		printf("%c", *s);
		if (p->sum == 1)       //前缀数为1
			return;
		s++;
	}
}
int main()
{
	root = new tree;
	char c[1020][30];
	for (int i = 0;i < 26;i++)
	{
		root->next[i] = NULL;
		root->sum = 0;
	}
	int i = 0;
	while (scanf("%s",c[i]) > 0 && c[i][0] != '\0')
	{
		insert(c[i]);
		i++;
	}
	for (int j = 0;j < i;j++)
	{
		printf("%s ", c[j]);
		Search(c[j]);
		printf("\n");
	}
	return 0;
}
