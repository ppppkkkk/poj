#include <iostream>
#include <cstring>
using namespace std;

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
