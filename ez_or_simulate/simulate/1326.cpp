#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
一家航空公司优惠政策，可以挣里程数。具体规则看表
你的任务是算里程数
*/

int main()
{
    string str1, str2;
    char ch;
    int length, sum = 0;
    while (cin >> str1)
    {
        if (str1 == "0")
        {
            cout  << sum << endl;
            sum = 0;
            continue;
        }
        else if (str1 == "#")
            break;
        else
        {
            cin >> str2 >> length >> ch;
            if (ch == 'F')
            {
                length = length * 2;
                sum += length;
            }
            if (ch == 'B')
            {
                sum += length;
                sum += (length * 1.0 / 2.0 + 0.5);

            }
            if (ch == 'Y')
            {
                if (length < 500) 
                    length = 500; 
                sum += length;
            }
        }


    }
    return 0;
}

