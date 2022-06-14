#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
using namespace std;

/*
Input
12
4873279
ITS-EASY
888-4567
3-10-10-10
888-GLOP
TUT-GLOP
967-11-11
310-GINO
F101010
888-1200
-4-8-7-3-2-7-9-
487-3279

Output
310-1010 2
487-3279 4
888-4567 3

*/



//将字母转换为数字
char convert(char c){
         if(c <= 'C') return '2';
         else if(c <= 'F') return '3';
         else if(c <= 'I') return '4';
         else if(c <= 'L') return '5';
         else if(c <= 'O') return '6';
         else if(c <= 'S') return '7';
         else if(c <= 'V') return '8';
         else if(c <= 'Y') return '9';
}
int main()
{
    int n;//用例数
    cin >> n;
    map<string,int> telp_count;//储存每个电话号码出现的次数
    while(n--){
        string s,res;
        cin >> s;
        int i = 0;
       for(string::iterator s_it = s.begin(); s_it != s.end(); ++s_it){
             if(*s_it >= '0' && *s_it <= '9') res.push_back(*s_it);
             if(*s_it >= 'A' && *s_it <= 'Z') res.push_back(convert(*s_it));
        }
        //在第三个数字后面插 -
        res.insert(3,1,'-');
        ++telp_count[res];
    }
    map<string,int>::iterator map_it = telp_count.begin();
    for(map_it = telp_count.begin() ; map_it != telp_count.end();++map_it)
        if(map_it->second >= 2){
            cout << map_it->first << " " << map_it->second << endl;
        }
    return 0;
}
