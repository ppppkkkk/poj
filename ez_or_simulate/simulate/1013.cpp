#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

/*
有12枚硬币。其中有11枚真币和1枚假币。假币和真币重量不同，但不知道假币比真币轻还是重。
现在，用一架天平称了这些币三次，告诉你称的结果，请你找出假币并且确定假币是轻是重(数据保证一定能找出来)。
枚举
*/

struct Coin {
    bool even;//平
    bool heavy;//重
    bool light;//轻
};

int main()
{
    int n;
    cin >> n;
    while (n--) {
        string left, right, result;
        Coin arr[12];
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < 3; i++) {
            cin >> left >> right >> result;
            int len = left.length();
            if (result == "even") {
                for (int i = 0; i < len; i++) {
                    arr[left[i] - 'A'].even = true;
                    arr[right[i] - 'A'].even = true;
                }
            }
            else {
                bool on[12] = { false };
                for (int i = 0; i < len; i++) {
                    on[left[i] - 'A'] = true;
                    on[right[i] - 'A'] = true;
                }
                for (int i = 0; i < 12; i++) {
                    if (!on[i]) {
                        arr[i].even = true;
                    }
                }
                if (result == "up") {
                    for (int i = 0; i < len; i++) {
                        arr[left[i] - 'A'].heavy = true;
                        arr[right[i] - 'A'].light = true;
                    }
                }
                else {
                    for (int i = 0; i < len; i++) {
                        arr[right[i] - 'A'].heavy = true;
                        arr[left[i] - 'A'].light = true;
                    }
                }
            }
        }
        for (int i = 0; i < 12; i++) {
            if (arr[i].even || (arr[i].heavy && arr[i].light))
                continue;
            if (arr[i].heavy) {
                cout << char('A' + i) << " is the counterfeit coin and it is heavy." << endl;
                break;
            }
            else if (arr[i].light) {
                cout << char('A' + i) << " is the counterfeit coin and it is light." << endl;
                break;
            }
        }
    }
    return 0;
}
