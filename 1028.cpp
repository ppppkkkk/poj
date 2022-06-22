#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;


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
