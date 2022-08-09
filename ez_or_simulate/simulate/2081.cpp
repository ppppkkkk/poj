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
Recaman的序列由a0 = 0定义； 对于m > 0，如果结果am为正且尚未在序列中，则am = am - 1 - m，否则am = am - 1 + m。
Recaman序列中的前几个数字是0、1、3、6、2、7、13、20、12、21、11、22、10、23、9 …
给定k，您的任务是计算ak
*/

int a[500001] = { 0 };
int main()
{
    map<int, int>Map;
    map<int, int>::iterator it;
    for (int i = 1;i < 500000;i++)
    {
        if (a[i - 1] - i > 0)
        {
            it = Map.find(a[i - 1] - i);
            if (it == Map.end())
                a[i] = a[i - 1] - i;
            else
                a[i] = a[i - 1] + i;
        }
        else
            a[i] = a[i - 1] + i;
        Map.insert(pair<int, int>(a[i - 1], 1));
    }
    int k;
    while (cin >> k && k != -1)
    {
        cout << a[k] << endl;
    }
    return 0;
}
