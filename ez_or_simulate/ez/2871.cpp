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

int main(int argc, char* argv[]) {
	float b = -1;
	float a;
	while (cin >> a, a != 999) {
		if (b == -1) {
			b = a;
			continue;
		}

		printf("%.2f\n", a - b);
		b = a;
	}

	cout << "End of Output" << endl;
	return 0;

}
