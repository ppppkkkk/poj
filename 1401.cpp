#include <iostream>
using namespace std;

/*

Sample Input

6
3
60
100
1024
23456
8735373

Sample Output

0
14
24
253
5861
2183837

*/


/*

求n的阶乘的结尾的0的个数
假设求60!的结果后面有几个0。
1,2,3……60中共有几个5的因子
5，10，15，20，25，30，35，40，45，50，55，60
共60/5 = 12（个）
25，50可以被25整除，即25和50可以贡献两个5的因子。
即其中可以贡献2个5的因子的个数为60/25 = 2（个）。
所以共有12 + 2 = 14 （个）5的因子。（即1 * 10 + 2 * 2)


*/

int main()
{
    int m;//用例数
    cin >> m;
    int n;//n的阶乘
    while(m--)
    {
        cin >> n;
        int ans = 0;
        while (n) 
        {
            ans = ans + n / 5;
            n = n / 5;
        }
        cout << ans << endl;
    }
    return 0;
}
