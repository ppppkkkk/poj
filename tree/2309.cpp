#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
* 树状数组
一个满二叉树，给一个数字，求以这个数为根的树中最大值和最小值。
lowbit就是求该数在二进制下最低位1的位置所代表的值
输入一个数x，得到该数二进制最右1的位置，假设为m，则以x为根的满二叉树的左子树的范围为[min,x-1]，
右子树的范围为[x+1,max]，并且，节点数为2^m-1，所以：
1、x-1-min+1 = (2^m-1-1)/2 - 1 = lowbit(x) - 1
2、max-(x+1)+1 = (2^m-1-1)/2
所以 min = x-lowbit(x)+1     max = x+lowbit(x)-1
*/





int lowbit(int n)
{
    return n & (-n);
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int k;
        scanf("%d", &k);
        printf("%d %d\n", k - lowbit(k) + 1, k + lowbit(k) - 1);
    }
    return 0;
}
