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
    map<string, int> m;
    string name;
    int count = 0;
    while (getline(cin, name))
    {
        m[name]++;
        count++;
    }
    for (map<string, int>::iterator map_it = m.begin(); map_it != m.end(); ++map_it)
    {
        cout << map_it->first << ' ' << fixed << setprecision(4) << (map_it->second) * 100.0 / count << endl;
    }
}

