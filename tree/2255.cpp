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
根据任意二叉树的先序遍历和中序遍历求解后序遍历
*/



const int MAX = 1010;

class Node 
{
	public:
		char value;
		Node* left;
		Node* right;
};

Node* BuildTree(char* p, char* In, int length) {
	if (length == 0)	
		return NULL;//终止条件，当length == 0时，即查询到最左边或者最右边的叶子节点。
	Node* temp = new Node();
	int pos;//找中轴
	for (pos = 0;pos < length;++pos) 
	{
		if (In[pos] == p[0])
			break;
	}
	temp->value = p[0];
	temp->left = BuildTree(p + 1, In, pos);
	temp->right = BuildTree(p + pos + 1, In + pos + 1, length - pos - 1);
	return temp;
}

void postOrder(Node* p) {
	if (p == NULL)	
		return;
	postOrder(p->left);
	postOrder(p->right);
	printf("%c", p->value);
}


int main() 
{
	char pre[MAX], in[MAX];
	while (scanf("%s%s", pre, in) != EOF) 
	{
		Node* father = BuildTree(pre, in, (int)strlen(pre));
		postOrder(father);
		printf("\n");
	}
	return 0;
}
