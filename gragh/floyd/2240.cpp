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
大概就是说，有n种货币，然后输入m种对换方式（单向），
只要其中有任意一种货币在经过交换后回到源点能比原来的值还要大，那么就输出Yes，反之输出No
Floyd
*/



using namespace std;

map<string, int> nameToId;
int n, m;
double edge[50][50];

int floyd()
{
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            for (int k = 1; k <= n; k++) 
                    edge[i][k] = max(edge[i][k],edge[i][j] * edge[j][k]);          
  //当货币从i换到k时，有另外一种走法，就是从i走到j，再从j走到k，此时如果是另一种走法会使得货币升值，那么就讲i到k的汇率换成edge[i][j] * edge[j][k]。
    for (int i = 1; i <= n; i++) 
        if (edge[i][i] > 1) 
            return 1;
        
    return 0;
}

int main()
{
    string name1, name2;
    double rate;
    int x, y, k = 1;

    while (cin >> n, n) 
    {
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                edge[i][j] = (i == j ? 1 : 0);
            }
        }
        for (int i = 1; i <= n; i++) 
        {
            cin >> name1;
            nameToId.insert(pair<string, int>(name1, i));
        }
        cin >> m;
        for (int i = 1; i <= m; i++) 
        {
            cin >> name1 >> rate >> name2;
            x = nameToId[name1];
            y = nameToId[name2];
            edge[x][y] = rate;
        }
        cout << "Case " << k++ << ": ";
     
        if (floyd()) 
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }

    return 0;
}
