#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
poj 1016

题目描述： 定义一个整数的inventory为：从0到9排列的(数字的个数+数字)。
例如”5553141”里面有2个1、1个3、1个4、3个5。所以”21131435”是”5553141”的inventory。
定义一个整数的第n(n>1)个inventory为：它的第n-1个inventory的inventory。
定义一个整数进入一个长度为n的inventory循环为：它的第n个inventory是它本身。

如果一个数的inventory是它本身，则说它是self-inventory的。
如果一个数的第n个inventory是self-inventorying的，则说它在第n步之后是self-inventorying的。
如果一个数进入了一个长度为k的inventory循环，则说它enters an inventory loop of length k。
如果一个数的前15个inventory都不满足上述三个条件的话，则说它can not be classified after 15 iterations
输入格式：有多组数据，每组数据输入一行，每行一个整数n，n为-1时结束输入
输出格式：每组数据都输出下面四句话中的一句：

n is self-inventorying
n is self-inventorying after j steps
n enters an inventory loop of length k
n can not be classified after 15 iterations
数据约定：n最大不超过80位。



*/

void R(char n[85], char t[85])
{
    int i, j;
    int time[10] = { 0 };
    for (i = 0;n[i];i++)
        time[n[i] - '0']++;

    for (i = 0, j = 0;i < 10;i++)
    {
        if (time[i])
        {
            if (time[i] < 10)
            {
                t[j++] = time[i] + '0';
                t[j++] = i + '0';
            }
            else
            {
                t[j++] = time[i] / 10 + '0';
                t[j++] = time[i] % 10 + '0';
                t[j++] = i + '0';
            }
        }
    }
    t[j] = '\0';

    return;
}

int main()
{
    int i, j;
    int flag1, flag2, flag3;
    char n[16][85];
    while (scanf("%s", n[0]) && (n[0][0] != '-'))
    {
        flag1 = flag2 = flag3 = 0;
        for (i = 1;i <= 15;i++)
        {
            R(n[i - 1], n[i]);
        }
        if (!strcmp(n[0], n[1]))
        {
            flag1 = 1;
        }
        if (!flag1)
        {
            for (i = 1;i < 15;i++)
            {
                if (!strcmp(n[i], n[i + 1]))
                {
                    flag2 = i;
                    break;
                }
            }
            if (!flag2)
            {
                for (j = 1;j <= 15;j++)
                {
                    for (i = 0;i <= j - 2;i++)
                    {
                        if (!strcmp(n[i], n[j]))
                        {
                            flag3 = j - i;
                            break;
                        }
                    }
                    if (flag3)
                        break;
                }
            }
        }
        if (flag1)
            printf("%s is self-inventorying\n", n);
        else if (flag2)
            printf("%s is self-inventorying after %d steps\n", n, flag2);
        else if (flag3)
            printf("%s enters an inventory loop of length %d\n", n, flag3);
        else
            printf("%s can not be classified after 15 iterations\n", n);
    }
    return 0;
}
