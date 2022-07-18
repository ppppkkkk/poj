#include <iostream>
#include <cstring>
using namespace std;


/*
poj 1088 
二维动态规划
为了获得速度，滑雪的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长底滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子
 1  2  3  4 5

16 17 18 19 6

15 24 25 20 7

14 23 22 21 8

13 12 11 10 9

一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。


*/




int height[101][101];
int length[101][101];

int r, c;

int getLength(int i, int j) {
	if (i < 0 || i >= r || j < 0 || j >= c)
		return -1;
	if (length[i][j] != 0)
		return length[i][j];	//已经得到结果的子问题直接返回结果 
	int temp = 0;
	if (height[i][j] > height[i - 1][j])							//四个方向上若比当前点高度低则递归 
		temp = max(temp, getLength(i - 1, j) + 1);
	if (height[i][j] > height[i + 1][j])
		temp = max(temp, getLength(i + 1, j) + 1);
	if (height[i][j] > height[i][j - 1])
		temp = max(temp, getLength(i, j - 1) + 1);
	if (height[i][j] > height[i][j + 1])
		temp = max(temp, getLength(i, j + 1) + 1);
	return temp;
}

int main() {
	int ans = 0;
	cin >> r >> c;
	for (int i = 0;i < r;i++)
		for (int j = 0;j < c;j++)
			cin >> height[i][j];
	memset(length, 0, sizeof(length));
	for (int i = 0;i < r;i++)
		for (int j = 0;j < c;j++) {
			length[i][j] = getLength(i, j);					//将每个子问题的结果保存在数组length中 
			ans = max(ans, length[i][j]);
		}
	cout << ans + 1;											//开始点没算长度这里补上 
	return 0;
}
