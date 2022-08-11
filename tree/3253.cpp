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
有一块长木头，要锯n-1次，锯成n块，锯多长就花多少钱，求花的最少的钱
*/

//构造小顶堆，即堆顶为最小的元素
priority_queue<int, vector<int>, greater<int> >q;
//优先队列
//用队列模拟树
int main()
{
    int n, t;
    while (cin >> n)
    {
        while (!q.empty()) 
            q.pop();//清空
        for (int i = 0;i < n;i++)
        {
            cin >> t;//输入叶子节点权值
            q.push(t);//放入堆中
        }
        long long ans = 0;//保存结果
        while (q.size() > 1)//堆中元素大于1个
        {
            int a = q.top();//取出堆顶元素作为左儿子
            q.pop();
            int b = q.top();//取出a后的堆顶元素作为右儿子
            q.pop();
            ans += a + b;//父节点作为非叶子节点,权值为a+b
            q.push(a + b);//父节点权值放回堆中
        }
        cout << ans << endl;//输出答案
    }
    return 0;
}
