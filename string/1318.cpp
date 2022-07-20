#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*

poj 1318

给定一个字典，字典里最多有１００个单词，每个单词最多６个字母，
输入：按照一定的方式输入字母，看在字典中是否有具有相同字母的单词，若有，将其输出，若无输出NOT A VALID WORD

*/

int main()
{
    string strd[105];
    string dict[105];
    string ans[105];
    string str, str1;
    int k = 0;
    int i, t;
    while (cin >> str1, str1 != "XXXXXX")
    {
        strd[k] = str1;
        dict[k] = str1;
        sort(dict[k].begin(), dict[k].end());
        k++;
    }
    while (cin >> str, str != "XXXXXX")
    {
        for (i = 0;i < 105;i++)
            ans[i].clear();
        t = 0;
        sort(str.begin(), str.end());
        for (i = 0; i < k; i++)
        {
            if (dict[i] == str)
            {
                ans[t++] = strd[i];
            }
        }
        if (t == 0)
            cout << "NOT A VALID WORD" << endl;
        sort(ans, ans + t);
        for (i = 0;i < t;i++)
            cout << ans[i] << endl;
        cout << "******" << endl;
    }
    return 0;
}
