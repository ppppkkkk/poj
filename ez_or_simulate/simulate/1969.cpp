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
按照s型分别给数编号
*/

int main()
{
    int n;
    while (cin>>n)
    {
        int s = 0, k = 1;
        while (1)
        {
            s += k;//统计个数，当前几斜线和大于了规定的序号，说明此时该数在第k根斜线
            if (s >= n)
            {//将分子和分母关系图分为两块，斜线分为两种，第奇数条
                if (k % 2) 
                    printf("TERM %d IS %d/%d\n", n, s - n + 1, k - s + n);//第奇数条
                else 
                    printf("TERM %d IS %d/%d\n", n, k - s + n, s - n + 1);//第偶数条
                break;
            }
            k++;
        }
    }
    return 0;
}
