#include<iostream>
using namespace std;
 
int length(int n)
{
    int len = 1;
    while (n != 1)
    {
        if(n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = 3 * n + 1;
        }
        len ++;
    }
    return len;
}
 
 
int main()
{
    int a, b;
    while(cin >> a >> b)
    {
        int max = -1;
        int x = a > b ? b : a;
        int y = a > b ? a : b;
        for (int i = x; i <= y; ++ i)
        {
            int temp = length(i);
            max = max > temp ? max : temp;
        }
        cout << a << " " << b << " " << max << endl;
    }
 
    return 0;
}
