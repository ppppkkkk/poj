#include<cstdio>
#include<string>


/*

poj 1008
Haab历转化成Tzolkin历

Sample Input
3
10. zac 0
0. pop 0
10. zac 1995

Sample Output
3
3 chuen 0
1 imix 0
9 cimi 2801
*/

int main()
{
    int n;
    int d, y;
    char m[20];
    char H[20][10] = { "pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet" };
    char T[22][10] = { "ahau","imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac" };

    scanf("%d", &n);
    getchar();
    printf("%d\n", n);
    while (n--)
    {
        int i = 0;
        scanf("%d. %s %d", &d, m, &y);
        for (; i < 19; i++)
            if (strcmp(m, H[i]) == 0)
                break;

        /* 计算一共经过了多少天 */
        d += i * 20 + y * 365;
        /* 按新历法规则输出 */
        
        printf("%d %s %d\n", d % 13 + 1, T[(d + 1) % 20], d / 260);
    }
    return 0;
}
