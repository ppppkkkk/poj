#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
对消息原文中的每个字母，分别用该字母之后的第5个字母替换（例如：消息原文中的每个字母A都分别替换成字母F）
*/

int main(void)
{
    char s[201];
    while (gets(s))
    {
        // 判断开始：START
        if (strcmp(s, "START") == 0)
            continue;

        // 判断报文结束：END
        if (strcmp(s, "END") == 0)
            continue;

        // 判断结束：ENDOFINPUT
        if (strcmp(s, "ENDOFINPUT") == 0)
            break;

        // 译码
        
        for (int i = 0;i<strlen(s);i++)
        {
            if (s[i] >= 'F' && s[i] <= 'Z')
                s[i] -= 5;
            else if (s[i] >= 'A' && s[i] < 'F')
                s[i] += 21;

        }

        // 输出结果
        printf("%s", s);
    }
    return 0;
}
