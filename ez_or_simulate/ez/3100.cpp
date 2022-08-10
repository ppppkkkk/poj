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
输入两个数字B和N。要求找一个A,使得A^N最接近B。
*/


int main()
{
    int B, N;
    while (cin >> B >> N , B , N) 
    {
        double temp = pow(B, 1.0 / N);
        int low = (int)temp;
        int high = (int)temp + 1;
        double temp1 = pow(low, 1.0 * N);
        double temp2 = pow(high, 1.0 * N);
        if ((B - temp1) <= (temp2 - B))  
            cout << low << endl;
        else cout << high << endl;
    }
    return 0;
}
