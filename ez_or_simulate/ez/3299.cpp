#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    double H, D, T;
    int h, t, d;
    char c;
    while (cin >> c && c != 'E') {
        h = t = d = 1;
        switch (c) {
        case 'H':   h = 0; cin >> H; break;
        case 'D':   d = 0; cin >> D; break;
        case 'T':   t = 0; cin >> T; break;
        }
        cin >> c;
        switch (c) {
        case 'H':   h = 0; cin >> H; break;
        case 'D':   d = 0; cin >> D; break;
        case 'T':   t = 0; cin >> T; break;
        }
        if (t)
            T = H - 0.5555 * (6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (D + 273.16)))) - 10.0);
        else if (d)
            D = 1 / (1 / 273.16 - log(((H - T) / 0.5555 + 10) / 6.11) / 5417.7530) - 273.16;
        else
            H = T + 0.5555 * (6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (D + 273.16)))) - 10.0);
        printf("T %.1f D %.1f H %.1f\n", T, D, H);
    }



    return 0;
}
