#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

/*

给定一个正整数n，编写一个程序以找出n的非零倍数m，其十进制表示形式仅包含数字0和1。
您可以假定n不大于200，并且对应的m包含不超过100十进制数字。
G++可过
*/

void bfs(int n)//对二进制数进行判断
{
    queue<long long >q;
    q.push(1);
    while (!q.empty())
    {
        long long ls = q.front();
        if (ls % n != 0)//不是n的倍数将两个子数入队
        {//两个子数分别是0和1
            q.push(ls * 10);
            q.push(ls * 10 + 1);
        }
        else
        {
            cout << ls << endl;
            return;
        }
        q.pop();
    }
}
int main()
{
    int n;
    while (cin >> n,n)
    {
        bfs(n);
    }
    return 0;
}

