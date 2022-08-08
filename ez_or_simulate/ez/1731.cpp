#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
using namespace std;
/*

*/
int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    do 
    {
        cout << s << endl;
    }while (next_permutation(s.begin(), s.end()));
    return 0;
}
