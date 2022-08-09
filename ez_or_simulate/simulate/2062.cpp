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

struct player
{
    int no;
    int type;
};

player adam[28];
player eve[28];


int getnum(char s[3])
{
    int number = 0;
    if (s[0] >= '2' && s[0] <= '9')
        number = s[0] - '0';
    if (s[0] == 'T')
        number = 10;
    if (s[0] == 'J')
        number = 11;
    if (s[0] == 'Q')
        number = 12;
    if (s[0] == 'K')
        number = 13;
    if (s[0] == 'A')
        number = 14;
    return number;
}

bool cmp(const player& a, const player& b)
{
    if (a.no == b.no)
        return a.type < b.type;
    else return a.no < b.no;
}


int main()
{
    int Case;
    char card[3];
    int card_num;
    scanf("%d", &Case);
    while (Case--)
    {
        scanf("%d", &card_num);
        for (int i = 0;i < card_num;i++)
        {
            cin >> card;
            int num = getnum(card);
            adam[i].no = num;
            if (card[1] == 'C')
                num = 1;
            if (card[1] == 'D')
                num = 2;
            if (card[1] == 'S')
                num = 3;
            if (card[1] == 'H')
                num = 4;
            adam[i].type = num;
        }
        sort(adam, adam + card_num, cmp);
        for (int i = 0;i < card_num;i++)
        {
            cin >> card;
            int num = getnum(card);
            eve[i].no = num;
            if (card[1] == 'C')
                num = 1;
            if (card[1] == 'D')
                num = 2;
            if (card[1] == 'S')
                num = 3;
            if (card[1] == 'H')
                num = 4;
            eve[i].type = num;

        }
        sort(eve, eve + card_num, cmp);
        int Count = 0;
        int flag = 0;
        for (int i = 0;i < card_num;i++)
            for (int j = flag;j < card_num;j++)
            {
                if (eve[j].no > adam[i].no || (eve[j].no == adam[i].no && eve[j].type > adam[i].type))
                {
                    Count++;
                    flag = j + 1;
                    break;
                }
            }
        printf("%d\n", Count);
    }
    return 0;
}
