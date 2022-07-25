#include "cstdio"
#include "iostream"
using namespace std;
int ratio[31][31];
int dir[5][2] = { 0,0,-1,0,1,0,0,-1,0,1 };

/*
poj 1222

给定一个5×6的01矩阵，改变一个点的状态时它上下左右包括它自己的状态都会翻转，
因为翻转2次等价与没有翻转，那么每个点要么不翻转，要么翻转一次，
求最终要怎样翻转可以使得矩阵全0


*/


void reset()
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 6; j++)
            for (int k = 0; k < 5; k++)
            {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if (x >= 0 && y >= 0 && x < 5 && y < 6) 
                    ratio[i * 6 + j][x * 6 + y] = 1;
            }
}
void guess()
{
    for (int i = 0;i < 30;i++)
    {
        int k = i;
        for (;k < 30;k++)
            if (ratio[k][i] != 0) 
                break;
        for (int j = 0;j <= 30;j++) 
            swap(ratio[i][j], ratio[k][j]);
        for (int j = 0;j < 30;j++)
        {
            if (i != j && ratio[j][i])
                for (int k = 0;k <= 30;k++)
                    ratio[j][k] = ratio[i][k] ^ ratio[j][k];
        }
    }
}
int main()
{
    int T, no = 0;
    scanf("%d", &T);
    while (T--)
    {
        printf("PUZZLE #%d\n", ++no);
        reset();
        for (int i = 0;i < 30;i++) scanf("%d", &ratio[i][30]);
        guess();
        for (int i = 0;i < 30;i++)
        {
            printf("%d", ratio[i][30]);
            if (i % 6 == 5) printf("\n");
            else printf(" ");
        }

    }
}
