#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

/*
给出1900-1999 年中任一一年的事件，
(d.m.p)，分别表示日、月、重要度（提前p天需要通知）。
然后给出n个时间点，要求输出需要提醒的日期。
*/


struct event
{
    int t; //累积时间
    int r; //重要性
    int d; //开始日
    int m; //开始月
    int id;//事件月份
    char name[250];
    bool operator<(const event& pos) const
    {
        if (t != pos.t) return t < pos.t;
        else if (r != pos.r) return r > pos.r;
        else return id < pos.id;
    }
};
int common[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
vector<event> day[400];


int main()
{
    int year;
    int id = 0;
    bool flag = false;
    scanf("%d", &year);
    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
        common[2] = 29;
    
    for (int i = 2; i <= 12; i++)
        common[i] += common[i - 1];
    
    while (true)
    {
        char ch[5];
        char str[300];
        cin >> ch;
        if (ch[0] == '#') break;
        else if (ch[0] == 'A')
        {

            int d, m, p;
            scanf("%d%d%d", &d, &m, &p);
            cin >> str;
            while (str[0] == ' ')
            { //去除多余空格
                for (int i = 0; i < strlen(str); i++)
                    str[i] = str[i + 1];
            }

            for (int i = max(1, common[m - 1] + d - p); i <= common[m - 1] + d; i++)
            {
                event tmp;
                tmp.d = d;
                tmp.m = m;
                tmp.id = id;
                strcpy(tmp.name, str);
                if (i != common[m - 1] + d)//星号
                    tmp.r = p - (common[m - 1] + d - i - 1);
                else
                    tmp.r = 8;
                tmp.t = common[m - 1] + d;//
                day[i].push_back(tmp);
            }
            for (int i = common[12] + common[m - 1] + d - p; i <= common[12]; i++)
            {
                event tmp;
                tmp.d = d;
                tmp.m = m;
                tmp.id = id;
                strcpy(tmp.name, str);
                tmp.r = p - (common[m - 1] + d - 1 + common[12] - i);
                tmp.t = common[m - 1] + d + common[12];
                day[i].push_back(tmp);
            }
            id++;
        }
        else if (ch[0] == 'D')
        {
            //排序
            if (!flag)
            {
                flag = true;
                for (int i = 0; i <= common[12]; i++)
                    sort(day[i].begin(), day[i].end());
            }
            int d, m;
            scanf("%d%d", &d, &m);
            printf("Today is:%3d%3d\n", d, m);
            for (int i = 0; i < day[common[m - 1] + d].size(); i++)
            {
                printf("%3d%3d ", day[common[m - 1] + d][i].d, day[common[m - 1] + d][i].m);
                if (day[common[m - 1] + d][i].t == common[m - 1] + d)
                    printf("*TODAY*");
                else
                {
                    for (int j = 0; j < day[common[m - 1] + d][i].r; j++)
                        printf("*");
                    for (int j = day[common[m - 1] + d][i].r + 1; j < 8; j++)
                        printf(" ");
                }
                printf(" %s\n", day[common[m - 1] + d][i].name);
            }
            printf("\n");
        }

    }
    return 0;
}
