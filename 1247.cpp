#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;



/*
poj1247

给一个环形，分别从头尾走，将N个数均分成两部分
Sample Input

5 9 4 2 8 3
5 3 9 4 2 8
6 1 2 1 2 1 2
6 1 2 1 2 1 1
0

Sample Output

Sam stops at position 2 and Ella stops at position 3.
No equal partitioning.
No equal partitioning.
Sam stops at position 3 and Ella stops at position 4.

*/

int main()
{
    int n;
    int num[50];
    int sumS, sumE;
    int S, E;//Sam,Ella
    while (cin >> n, n)
    {
        for (int i = 1;i <= n;i++)
        {
            cin >> num[i];
        }
        sumS = num[1];
        sumE = num[n];//分别从头尾开始累加
        S = 1;
        E = n;
        while (E - S > 1) 
        {
            if (sumS < sumE) 
            {
                S++;
                sumS = sumS + num[S];
            }
            else
            {
                E--;
                sumE = sumE + num[E];
            }
        }
        if (sumS == sumE)
            printf("Sam stops at position %d and Ella stops at position %d.\n", S, E);
        else
            cout << "No equal partitioning." << endl;
    }
    return 0;
}

