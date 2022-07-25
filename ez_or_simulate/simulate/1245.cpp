#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

/*
* poj 1245
团队按解决的问题数量排在首位，
然后按总时间最少，
然后按所有非零时间的几何平均数最少。
仍然并列的球队将获得相同的数字排名，并按字母顺序列出，


*/



struct rank {
    char name[12];
    int solve, totaltime, avgtime, p[7], ind;
};
rank ranks[25];

int cmp(const void * c, const void * d)
{
    rank* a = (rank*)c;
    rank* b = (rank * )d;
    if (a->solve > b->solve) return -1;
    else if (a->solve < b->solve) return 1;
    else {
        if (a->totaltime < b->totaltime) return -1;
        else if (a->totaltime > b->totaltime) return 1;
        else {
            if (a->avgtime < b->avgtime) return -1;
            else if (a->avgtime > b->avgtime) return 1;
            else {
                return strcmp(a->name, b->name);
            }
        }
    }

}

int main()
{
    int n = 0, cnt = 1;
    while (scanf("%d", &n)) {
        if (!n) break;
        for (int i = 0; i < n; i++) {
            double t = 0;
            ranks[i].solve = 0, ranks[i].totaltime = 0, ranks[i].avgtime = 0;
            scanf("%s", &ranks[i].name);
            for (int j = 0; j < 7; j++) {
                scanf("%d", &ranks[i].p[j]);
                if (ranks[i].p[j]) {
                    ranks[i].solve++;
                    ranks[i].totaltime += ranks[i].p[j];
                    t += log((double)ranks[i].p[j]);
                }
            }
            if (ranks[i].solve > 0) {
                ranks[i].avgtime = exp(t / ranks[i].solve) + 0.5;
            }
        }
        qsort(ranks, n, sizeof(rank), cmp);
        printf("CONTEST %d\n", cnt);
        cnt++;
        for (int i = 0; i < n; i++) {
            if (i < 9) {
                printf("0");
            }
            if (i > 0 && ranks[i].solve == ranks[i - 1].solve && ranks[i].totaltime == ranks[i - 1].totaltime && ranks[i].avgtime == ranks[i - 1].avgtime) {
                ranks[i].ind = ranks[i - 1].ind;
            }
            else {
                ranks[i].ind = i + 1;
            }
            printf("%d %-10s %d %4d %3d %3d %3d %3d %3d %3d %3d %3d\n", ranks[i].ind, ranks[i].name, ranks[i].solve, ranks[i].totaltime, ranks[i].avgtime,
                ranks[i].p[0], ranks[i].p[1], ranks[i].p[2], ranks[i].p[3], ranks[i].p[4], ranks[i].p[5], ranks[i].p[6]);

        }

    }
    return 0;
}
