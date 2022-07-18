#include <stdio.h>

/*

poj 1032

给出一个数n,将其拆分为若干个互不相等的数字的和,要求这些数字的乘积最大
我们得到最大的乘积的做法就是求出从2开始的最大连续（由上面总结的性质2和3可知）自然数列之和A，使得A的值不超过N，具体分析如下：
对输入的N，找到k满足：
A=2+3+4+...+(k-1)+k <= N < A+(k+1) = B
假设N=A+p（0<=p< k+1），即A+p是最大积的数列
1）p=0，则最大积是A；
2）1<=p<=k-1，则最大积是B-{k+1-p}，即从数列的最大项i开始，从大到小依次每项加1，知道p=0为止；
3）p=k，则最大积是A+p=A+k=A-{2}+{k+2}；( =3+4+...+k+( k+2) )；
*/


int main()
{
    int n, j;
    scanf("%d", &n);
    int i = 2;
    int sum = 0;
    while (sum + i <= n)
    {
        sum += i;
        i++;
    }
    int diff = n - sum;
    if (diff == i - 1)
    {
        for (j = 3;j < i;j++)
            printf("%d ", j);
        printf("%d\n", j + 1);
    }
    else
    {
        for (j = 2;j < i - diff;j++)
            printf("%d ", j);
        for (j = i - diff;j < i;j++)
            printf("%d ", j + 1);
        printf("\n");
    }
    return 0;
}
