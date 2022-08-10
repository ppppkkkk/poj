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
求最小子串的循环次数
*/

int Next[1000001];
void getNext(char T[],int len)//创建KMP中next数组
{
    int i = 0, j = -1;
    Next[0] = -1;
    while (i < len)
    {
        if (j == -1 || T[i] == T[j])
        {
            i++;
            j++;
            Next[i] = j;
        }
        else
            j = Next[j];
    }
}

int main()
{
    char a[1000001];
    while (~scanf("%s", a),a[0]!='.')
    {
        int len = strlen(a);
        getNext(a,len);
        int length = len - Next[len];
        if (len % length == 0)
            printf("%d\n", len / length);
        else
            printf("1\n");
    }
    return 0;
}

