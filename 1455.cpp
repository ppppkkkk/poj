#include<iostream>
#include<cstdio>
using namespace std;

/*
有n个人形成一个圆环。比如：a左边b，b左边c，最后一个假设是g，那么他左边必然是a。
规定每次只能相邻两个人进行交换位置。
请问要经过多少次交换，才能让之前位置交换（b左边a，c左边b，a左边是g）

假定N的环形，分成一个长度为k，另一个长度是N-k的线段。
那么需要交换的次数为：
k*(k-1)/2
(N-k)*(N-k-1)/2
相加后就是需要交换的总次数。
题目要求交换次数最少。
那么就是求
k*(k-1)/2+ (N-k)*(N-k-1)/2的最小值。


Sample Input

3
4
5
6
Sample Output

2
4
6

*/





int main() {
    int t, n, k, ans;
    cin >> t;//用例数
    while (t--) 
    {
        cin >> n;//n个人
        if (n == 1)
            cout << "0" << endl;
        else 
        {
            k = n / 2;
            cout<<(k * (k - 1) / 2 + (n - k) * (n - k - 1) / 2)<<endl;
        }
    }
    return 0;

}
