#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

/*
poj 1219
给出第一个字母。
猜测一个可能的五个字母的单词。
指示猜出的单词中的任何字母是否正确并且在密码中的相同位置，
*/


char in[100];
char str[100];

int illegal(string str)
{
    for (int i = 0; i < 5; i++)
    {
        if (str[i] < 'A' || str[i]>'Z')
            return 0;
    }
    return 1;
}
void change(string t, string& last)
{
    int i, j;
    int flag[10];
    memset(flag, 0, sizeof(flag));
    for (i = 0; i < 5; i++)
    {
        if (t[i] == in[i])
            flag[i] = 1;
    }
    for (i = 0; i < 5; i++)
    {
        if (t[i] == in[i])
            last += t[i];
        else
        {
            for (j = 0; j < 5; j++)
            {
                if (t[i] == in[j] && !flag[j])
                {
                    last += in[j] - 'A' + 'a';
                    flag[j] = 1;
                    break;
                }
            }
            if (j == 5)
                last += ".";
        }
    }
}

int main()
{
    getchar();
    while (gets_s(in))
    {
        if (!strcmp(in, "LINGO"))
            break;
        putchar(10);
        printf("%c....\n", in[0]);
        string t;
        string gin = in;
        string last;
        last = in[0];
        last += "....";
        int i, j, flag = 0;
        for (i = 0; i < 6; i++)
        {
            gets_s(str);
            t = str;
            if (t == gin)
            {
                printf("%s\n", gin.c_str());
                break;
            }
            else if (t == "")
            {
                flag = 1;
                break;
            }
            else
            {
                if (t.length() == 5 && illegal(t))
                {
                    last = "";
                    change(t, last);
                }
                if (i == 5)
                {
                    flag = 1;
                    break;
                }
                printf("%s\n", last.c_str());
            }
        }
        if (flag)
        {
            for (j = 0; j < 5; j++)
                printf("%c", gin[j] - 'A' + 'a');
            putchar(10);
        }
        while (strcmp(str, ""))
        {
            gets_s(str);
        }
    }
    return 0;
}
