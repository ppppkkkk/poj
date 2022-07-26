#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

/*
给出两个长度为len的字符串s1， s2和一个长度为2 * len的字符串s12，
每次先让s2先s1后先后依次取一个字符得到一个长度为2 * len 的字符串s，如果发现得到的字符串s与s12相等就输出交换的次数，
否则让s的左半边等于s1右半边等于s2再进行上面的变换，
如果无法使的变换后的s == s12则输出-1。
*/








int main()
{
    int t;
    string str[25];
    char temp[15];
    int visited[25];
    int pos[25];



    scanf("%d", &t);
    while (t--)
    {
        int n, m;//n操作数 m项目数
        scanf("%d%d", &n, &m);
        for (int i = 1;i <= n;i++)
        {
            scanf("%s", temp);
            str[i] = temp;
            pos[i] = visited[i] = 0;
        }




        while(m--)
        {
            int a, b;//b位置是a
            scanf("%d%d", &a, &b);
            visited[a] = 1;
            pos[b] = a;
        }


        for (int i = 1, j = 1;i <= n;i++)
        {
            if (pos[i] == 0)
            {
                while (visited[j])
                    j++;
                pos[i] = j++;
            }
        }
        for (int i = 1;i <= n;i++)
        {
            cout << str[pos[i]] << " ";
        }
        cout << endl;
    }
    return 0;
}
