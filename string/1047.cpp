#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

/*
* 
* 若一个n位的数字串满足下述条件，则称其是循环数（cyclic）：将这个数字串视为整数（可能带有前导0），并用任意一个 1 到 n 之间（包含1和n）的整数去乘它时, 会得到一个将原数字串首尾相接后，再在某处断开而得到的新数字串所对应的整数。例如，数字 142857 是循环数，因为:
142857 *1 = 142857
142857 *2 = 285714
142857 *3 = 428571
142857 *4 = 571428
142857 *5 = 714285
142857 *6 = 857142。

请写一个程序判断给定的数是否是循环数。



对于数N，若N为循环的则有N*(length(N)+1)=99....99， (length(N)个9)，length(N)为N的位数，含前导0
*/

string solve(const string& source)
{
    int i, j;
    string add;
    int len = source.length();
    for (i = 0;i < len;i++)//反转字符串便于计算
    {
        add.append(source, len - i - 1, 1);
    }
    string result(add);
    //将每个字符串当作一个整数相加len次，即乘以len+1
    for (i = 0;i < len;i++)
    {
        for (j = 0;j < len;j++)
        {
            int temp = (result[j] - '0') + (add[j] - '0');
            if (temp < 10)
                result[j] = temp + '0';
            else
            {
                temp -= 10;
                result[j] = temp + '0';
                result[j + 1] += 1;
            }
        }
    }
    return result;
}
int main()
{
    string digital, result;
    int i;
    while (cin >> digital)
    {
        result = solve(digital);
        string strn("");
        strn.reserve(digital.length());
        for (i = 0;i < digital.length();i++)
        {
            strn.append("9");
        }
        if (result == strn)
            printf("%s is cyclic\n", digital.c_str());
        else
            printf("%s is not cyclic\n", digital.c_str());
    }
    return 0;
}
