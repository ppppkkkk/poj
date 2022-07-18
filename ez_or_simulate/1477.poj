#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>

using namespace std;
/*
* 
给n个数，计算所有数跟平均值的差值总和


Sample Input

6
5 2 4 1 7 5
0

Sample Output

Set #1
The minimum number of moves is 5.

*/





int main()
{
    int n;
    int sum = 0, avg = 0, minus = 0,count = 0;
    int num[60];

    while (cin>>n, n)
    {
        count++;
        sum = avg = 0;
        for (int i = 1;i <= n;i++)
        {
            cin >> num[i];
            sum = sum + num[i];
        }
        avg = sum / n;
        minus = 0;
        for (int i = 1;i <= n;i++)
        {
            minus = minus + abs(num[i] - avg);
        }
        cout << "Set #" << count << endl;
        cout << "The minimum number of moves is " << minus / 2<<"." << endl;
        cout << endl;
    }
    return 0;
}
