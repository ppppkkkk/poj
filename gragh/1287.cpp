/*
    Kruskal 1287    Accepted    420K    16MS    G++
*/
#include"cstdio"
#include"algorithm"
using namespace std;
const int MAXN = 1000005;

/*

您被分配在广域内的某些点之间设计网络连接。在该区域中为您提供了一组点，以及可能连接成对点的电缆的一组可能路线。对于两点之间的每条可能路线，将为您提供在该路线上连接各点所需的电缆长度。请注意，两个给定点之间可能存在许多可能的路线。假定给定的可能路线（直接或间接）连接区域中的每两个点。
  您的任务是设计该区域的网络，以使每两个点之间都具有连接（直接或间接）（即，所有点都是互连的，但不一定是通过直接电缆），并且总长度为使用的电缆极少。
最小生成树

*/






struct Edge {
    int u, v, cost;
}es[MAXN];
bool cmp(const Edge& a, const Edge& b)
{
    return a.cost < b.cost;
}

int par[MAXN];
int rnk[MAXN];
void init(int n)
{
    for (int i = 0;i <= n;i++)
    {
        par[i] = i;
    }
}

int fnd(int x)
{
    if (par[x] == x)
    {
        return x;
    }
    return par[x] = fnd(par[x]);
}

void unite(int u, int v)
{
    int a = fnd(u);
    int b = fnd(v);
    if (a == b)    return;

    if (rnk[a] < rnk[b])
    {
        par[a] = b;
    }
    else {
        par[b] = a;
        if (rnk[a] == rnk[b])    rnk[a]++;
    }
}

bool same(int u, int v)
{
    return fnd(u) == fnd(v);
}

int main()
{
    int V, E;
    while (scanf("%d", &V) != EOF && V)
    {
        scanf("%d", &E);
        for (int i = 0;i < E;i++)
        {
            scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].cost);
        }
        sort(es, es + E, cmp);
        init(V);
        int ans = 0;
        int cnt = 0;
        for (int i = 0;i < E;i++)
        {
            if (!same(es[i].u, es[i].v))
            {
                unite(es[i].u, es[i].v);
                ans += es[i].cost;
                cnt++;
            }
            if (cnt == V - 1)    break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
