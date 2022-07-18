#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

/*
poj 1028栈模拟

首先，我们的浏览器先访问http://www.acm.org/。
然后，发出一些指令，每个指令发出后，打印指令结果。
指令表：

指令	含义	参数
QUIT	退出	无
BACK	返回上一个浏览的页面	无
FORWARD	如果BACK是“撤回”，那么它相当于“重做”	无
VISIT	访问一个新页面，之前执行“撤回”的url全部清空，此时无法执行“FORWARD”	url


*/

int main()
{
    stack<string> first;
    stack<string> temp;
    temp.push("http://www.acm.org/");
    string a, b;
    while (cin >> a)
    {
        if (a[0] == 'Q')break;
        if (a[0] == 'V')
        {
            cin >> b;
            temp.push(b);
            cout << b << endl;
            while (!first.empty())
                first.pop();
        }
        if (a[0] == 'B')
        {
            if (temp.size() > 1)
            {
                first.push(temp.top());
                temp.pop();
                cout << temp.top() << endl;
            }
            else
                cout << "Ignored" << endl;
        }
        if (a[0] == 'F')
        {
            if (first.size() > 0)
            {
                temp.push(first.top());
                cout << first.top() << endl;
                first.pop();
            }
            else
                cout << "Ignored" << endl;
        }
    }
    return 0;
}
