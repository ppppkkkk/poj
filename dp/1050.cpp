#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

/*

给你N^2个数字，构成一个矩阵，需要你从其中找出和最大的子矩阵

*/

const int N = 510;
int a[N][N], maxrow[N], row[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        memset(row, 0, N);
        for (int j = i; j < n; j++)
        {
            for (int c = 0; c < n; c++)
                row[c] += a[j][c];

            for (int c = 0; c < n; c++)
            {
                if (c == 0)
                    maxrow[c] = row[c];
                else 
                {
                    maxrow[c] = maxrow[c - 1] > 0 ? maxrow[c - 1] + row[c] : row[c];
                }
                ans = max(ans, maxrow[c]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}


