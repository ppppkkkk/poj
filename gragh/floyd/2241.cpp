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
/*
给你无数个各种类型的砖块，（不超过30种），选择一些木块把他们来推起来，要求下面的一层比上面的一层的变长都要短，问可以堆得最高高度
Floyd
*/



int n, num;
int maxcost[1005][1005];

struct point
{
    int x, y, z;
}box[10050];




void FLOYD()
{
    for (int k = 0;k < num;k++)
    {
        for (int i = 0;i < num;i++)
        {
            for (int j = 0;j < num;j++)
            {
                if (maxcost[i][k] != -1 && maxcost[k][j] != -1)
                    maxcost[i][j] = max(maxcost[i][j], maxcost[i][k] + maxcost[k][j]);
            }
        }
    }
    return;
}
int main()
{
    int Case = 1;
    int ans;
    while (cin>>n, n)
    {
        int inputx, inputy, inputz;
        num = 0;
        memset(maxcost, -1, sizeof(maxcost));
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d%d", &inputx, &inputy, &inputz);//六种摆法，按规律来小心重复；
            box[num].x = inputx, box[num].y = inputy, box[num++].z = inputz;
            box[num].x = inputx, box[num].y = inputz, box[num++].z = inputy;
            box[num].x = inputy, box[num].y = inputx, box[num++].z = inputz;
            box[num].x = inputy, box[num].y = inputz, box[num++].z = inputx;
            box[num].x = inputz, box[num].y = inputx, box[num++].z = inputy;
            box[num].x = inputz, box[num].y = inputy, box[num++].z = inputx;
        }
        for (int i = 0;i < num;i++)//建图，注意是单向图；
        {
            for (int j = 0;j < num;j++)
            {
                if (box[i].x > box[j].x && box[i].y > box[j].y)//建图的条件，上面的长和宽注意要严格小于下面的；
                {
                    maxcost[i][j] = box[j].z;
                }
            }
        }
        FLOYD();
        ans = -1;
        for (int i = 0;i < num;i++)
        {
            for (int j = 0;j < num;j++)
            {
                ans = max(ans, maxcost[i][j] + box[i].z);//这里要注意一下加上最下面的那个箱子的高度；
            }
        }
        printf("Case %d: maximum height = %d\n", Case++, ans);
    }
    return 0;
}

