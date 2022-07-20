#include<stdio.h>
#include<string.h>

/*
poj 1250
旅馆床位有限，按顺序入住，用ABC等代表单个人，第1次出现代表入住，第2次出现代表离开。求有多少位顾客未住店就离开了。

Sample Input
2 ABBAJJKZKZ
3 GACCBDDBAGEE
3 GACCBGDDBAEE
1 ABCBCA
0

Sample Output
All customers tanned successfully.
1 customer(s) walked away.
All customers tanned successfully.
2 customer(s) walked away.


*/

int main()
{
    int n;
    bool a[30];             //记录离开或者进入
    memset(a, 0, sizeof(a));
    char customer[1000];
    while (scanf("%d", &n) != EOF && n != 0)
    {
        scanf("%s", customer);
        int cust = strlen(customer); //进入进出的总数
        int leave = n;   //剩余的房间
        int i;
        int away = 0;       //流失的人
        for (i = 0;i < cust; i++)
        {
            if (a[customer[i] - 'A'] == false)
            {
                leave--;
                if (leave < 0)
                    away++;
                a[customer[i] - 'A'] = true;
                continue;
            }
            else
            {
                leave++;
                a[customer[i] - 'A'] = false;
                continue;
            }
        }
        if (away == 0)
            printf("All customers tanned successfully.\n");
        else
            printf("%d customer(s) walked away.\n", away);
    }
    return 0;
}
