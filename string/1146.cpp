//题意：按字典序找出字符串下一个全排序

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
int main ()
{
	string str;
	while (cin >> str)
	{
		if (str[0]=='#')
			break;
		if (next_permutation(str.begin(), str.end()))
			cout<<str<<endl;
		else
			printf("No Successor\n");
	}
    return 0;
}
