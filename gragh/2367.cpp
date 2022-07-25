#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
拓扑排序
*/

int g[101][102];
int indegree[102];//度
int res[102];
using namespace std;

int main()
{
    int n, p;
    scanf("%d", &n);
    
        memset(g, 0, sizeof(g));
        memset(indegree, 0, sizeof(indegree));
        for (int i = 1;i <= n;i++)
        {
            while (scanf("%d", &p), p)
            {
                g[i][p] = 1;
                indegree[p]++;
            }
        }
        int top = 0;//栈指针
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= n;j++)
            {
                if (indegree[j] == 0)
                {
                    res[top++] = j;
                    indegree[j] --;
                    for (int k = 1;k <= n;k++)
                        if (g[j][k] == 1)
                            indegree[k] --;
                    break;
                }
            }
        }
        for (int i = 0;i < top;i++)
        {
            if (i == top - 1)
                printf("%d\n",res[i]);
            else 
                printf("%d ", res[i]);
        }
    
    return 0;
}
