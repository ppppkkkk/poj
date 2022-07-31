#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;
/*
一个错误的键盘，输入的一个字母或字符时会变成这个字母或字符在键盘上位置右边的一个。 
然后已知输出的字符，求你原本输入的是什么
*/



char str[1100];
char g[1100] = { "1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./" };

int main()
{
    while (gets_s(str) != 0)
    {

        int len = strlen(str);
        for (int i = 0;i < len;i++)
        {
            char tmp = str[i];
            int j;
            for (j = 0;j < 1100;j++)
            {
                if (g[j] == tmp)
                    break;
            }
            if (j == 1100) 
                printf("%c", tmp);
            else
                printf("%c", g[j - 1]);
        }
        printf("\n");
    }
    return 0;
}

