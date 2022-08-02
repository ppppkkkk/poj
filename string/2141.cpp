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

//第一行为26个字符, 用来加密 第二行的字符随便写, 规则如下, 第二行第一个字符为K, 就从第一行找到第K个字符输出

int main() {
    char s1[100];
    char s2[100];
    cin.getline(s1,100);
    cin.getline(s2,100);
    for (int i = 0;i < strlen(s2);i++) {
        if (s2[i] >= 'a' && s2[i] <= 'z') {
            cout << s1[s2[i] - 'a'];
        }
        else if (s2[i] >= 'A' && s2[i] <= 'Z') {
            cout << (char)((int)(s1[s2[i] - 'a' + 32]) - 32);
        }
        else
            cout << s2[i];
    }
    cout << endl;
    return 0;
}
