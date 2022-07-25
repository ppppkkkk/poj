#include<iostream>
#include<cctype>
#include<cstring>
#include<string>
using namespace std;

/*
poj 1051
摩斯电码
根据每个字母与四个标点符号的摩尔电码以及每个所输入的摩尔电码的长度解密；

                    解密过程为先将长度串反转，然后再根据长度串找对应的摩尔电码；

                    实例：PUEL-->.--...-..-.. 4314-->4134-->PERL
*/


int main() {
    char a[][5] = { ".-","-...","-.-.","-..",".","..-.","--.",
                   "....","..",".---","-.-",".-..","--","-.",
                   "---",".--.","--.-",".-.","...","-","..-",
                   "...-",".--","-..-","-.--","--..",
                   "..--",".-.-","---.","----" };
    int tmp, start, i, j, len, count = 0, n, data[105];
    char source[105], target[405], mid[5];
    scanf("%d", &n);
    while (count < n) {
        memset(target, 0, sizeof(target));
        scanf("%s", source);
        len = strlen(source);
        for (i = 0;i < len;i++) {
            if (isalpha(source[i])) {
                data[i] = strlen(a[source[i] - 'A']);
                strcat(target, a[source[i] - 'A']);
            }
            else {
                data[i] = 4;
                if (source[i] == '_')    strcat(target, a[26]);
                if (source[i] == ',')    strcat(target, a[27]);
                if (source[i] == '.')    strcat(target, a[28]);
                if (source[i] == '?')    strcat(target, a[29]);
            }
        }
        for (i = 0;i < (len + 1) / 2;i++) {
            tmp = data[i];
            data[i] = data[len - 1 - i];
            data[len - 1 - i] = tmp;
        }
        printf("%d: ", ++count);
        start = 0;
        for (i = 0;i < len;i++) {
            if (i > 0)    start += data[i - 1];
            for (j = start;j < start + data[i];j++) {
                mid[j - start] = target[j];
            }
            mid[data[i]] = '\0';
            for (j = 0;j <= 29;j++) {
                if (strcmp(a[j], mid) == 0) {
                    if (j < 26)    printf("%c", 'A' + j);
                    if (j == 26)    printf("_");
                    if (j == 27)    printf(",");
                    if (j == 28)    printf(".");
                    if (j == 29)    printf("?");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
