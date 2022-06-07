//456666 p串
//(((()()())))
//111456


#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>
using namespace std;

int main()
{
    int t, n, p1, p2;
    cin>>t;//用例数
    while (t--)
    {
        cin>>n;//p串长度
        stack<int> sk;
        p1 = 0;//p1记录前一个p串字符
        for (int i = 0, l = 0, r = 0; i < n; i++)
        {
            cin>>p2;//输入p串字符每次一个
            for (int j = 0; j < (p2 - p1); j++)
            {
                sk.push(l);//将左括号位置进栈
                l++;//左指针向后移
            }
            r = i + p2;//右指针指向当前右括号位置
            l++;//左指针后移
            p1 = p2;//记录前一个p串字符
            printf("%d%c", (r - sk.top() + 1) / 2, i == n - 1 ? '\n' : ' ');//统计括号中有多少个成对的括号
            sk.pop();
        }
    }
}
