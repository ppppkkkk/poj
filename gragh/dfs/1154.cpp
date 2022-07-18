//莫名其妙出现问题，正解看poj1154
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

poj 1154
R行S列从左上角走，最多能走几步

*/

int map[30][30];//20*20
int visit[500];//标记
int step[4][2] = { -1,0,1,0,0,1,0,-1 };
int sum = 1;
int longest = 1;
int R, S;

void dfs(int x, int y)
{
    for (int i = 0;i < 4;i++)//四种走法
    {
        int newx = x + step[i][0];
        int newy = y + step[0][i];
        if (newx >= 1 && newx <= R && newy >= 1 && newy <= S && !visit[map[newx][newy]])
        {
            sum++;
            visit[map[newx][newy]] = 1;
            dfs(newx, newy);
            if (sum > longest)
            {
                longest = sum;
            }
            //dfs后复原环境
            sum--;
            visit[map[newx][newy]] = 0;
        }
    }
    return;
}

int main()
{
    char c;
    while (scanf("%d%d", &R, &S) != EOF)
    {
        memset(visit, 0, sizeof(visit));
        memset(map, 0, sizeof(map));
        getchar();
        for (int i = 1;i <= R;i++)
        {
            for (int j = 1;j <= S;j++)
            {
                scanf("%c", &c);
                map[i][j] = c - 'A';
            }
            getchar();
        }
        visit[map[1][1]] = 1;
        dfs(1, 1);
        cout << longest << endl;
    }
    return 0;
}

