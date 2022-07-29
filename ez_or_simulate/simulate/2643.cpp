#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;

/*
n个人有好几个个党派，投票出党派最多人的党派，
*/



int main()
{
    map<string, int>num;
    map<string, string>party;
    string s1, s2;
    int n, m;
    cin >> n;
    getchar();//吸收回车 
        for (int i = 0;i < n;i++)
        {
            getline(cin,s1);
            getline(cin,s2);
            party[s1] = s2;
        }
        cin >> m;
        getchar();
        while (m--)
        {
            getline(cin,s1);
            if (party[s1].size())
                num[s1]++;
        }
        int ans = -1, flag = 0;
        for (map<string, int>::iterator it = num.begin();it != num.end();it++)
        {
            if (it->second > ans)
            {
                ans = it->second;
                s1 = it->first;
                flag = 1;
            }
            else if (it->second == ans)
                flag++;
        }
        if (flag != 1)
            cout << "tie" << endl;
        else 
            cout << party[s1] << endl;
    
    return 0;
}
 
