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
每行输入一条循环活动指令的注册 格式大致为:Register [活动编号] [活动时间间隔], 以"#"号结尾 ,
完成注册以后便会按照时间先后执行, 如第一行为例子 , 2004代表编号 , 200代表活动执行间隔.
最后一行表示前n个被执行的活动
*/
struct Node
{
    int id;
    int period;
    int time;
    friend bool operator < (const Node& a, const Node& b)
    {
        if (a.time == b.time)
            return a.id > b.id;
        else
            return a.time > b.time;
    }
};

int main()
{
    priority_queue<Node> q;
    string s;
    Node point;
    int x, y;
    cin >> s;
    while (s.compare("#") != 0)
    {
        scanf("%d %d", &x, &y);
        point.id = x;
        point.period = y;
        point.time = y;
        q.push(point);
        cin >> s;
    }
    int n;
    scanf("%d", &n);
    while (n--)
    {
        Node temp = q.top();
        temp.time += temp.period;
        printf("%d\n", temp.id);
        q.pop();
        q.push(temp);
    }
}
