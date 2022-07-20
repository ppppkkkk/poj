#include<cstdio>
using namespace std;
/*
题意：给一个奇素数，求它原根的数目。

定理：如果p有原根，则他有phi(phi(p))个原根，p为素数是，phi(p) = p-1，原根数量就为phi(p-1)；

下面给出原根的求法：

对于数m，先求ϕ(m) 的素幂分解式，即

                φ(m) = p1^e1*p2^e2*……*pk^ek;

然后枚举g，若g满足g^(φ(m)/pi )!= 1 (mod m) ,i = 1,2,3……,k;

则g为m的一个原根

*/


int eu[66000], p;

void eular() {
    for (int i = 2;i <= 65536;++i)
        if (!eu[i])
            for (int j = i;j <= 65536;j += i) {
                if (!eu[j]) eu[j] = j;
                eu[j] = eu[j] / i * (i - 1);
            }
}

int main() {
    eular();
    while (~scanf("%d", &p)) {
        printf("%d\n", eu[p - 1]);
    }
    return 0;
}
