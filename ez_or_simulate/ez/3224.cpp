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
将n个学生比赛的结果存在一个n*n的数组中，aij为第i个学生胜出第j个人的比赛场数
找出每一行3最多的那个人，一样多则取在前的那一位
*/
int main()
{
    int n;
    int a[105][105];
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int maxIndex = 0;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 3)
                sum++;
        }
        if (sum > max)
        {
            max = sum;
            maxIndex = i;
        }
    }
    cout << maxIndex + 1 << endl;
    return 0;
}
