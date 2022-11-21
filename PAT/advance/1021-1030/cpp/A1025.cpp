#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct PAT {
    int loc_n;
    int rank_g = 1;
    int rank_l = 1;
    char regNum[14];
    int score;
} testcases[100 * 300];

bool cmp_l(PAT p1, PAT p2) {
    return p1.score > p2.score;
}

bool cmp_g(PAT p1, PAT p2) {
    if (p1.score != p2.score) return p1.score > p2.score;
    else return strcmp(p1.regNum, p2.regNum) < 0;
}

int main() {
    int n, k, total = 0, tmp;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        tmp = total;
        for (int j = 0; j < k; j++) {
            testcases[total].loc_n = i;
            scanf("%s%d", testcases[total].regNum, &testcases[total].score);
            total++;
        }
        sort(testcases + tmp, testcases + total, cmp_l);
        int r = 2;
        for (int q = tmp + 1; q < total; q++) {
            if (testcases[q].score != testcases[q-1].score) {
                testcases[q].rank_l = r;
            } else {
                testcases[q].rank_l = testcases[q-1].rank_l;
            }
            r++;
        } 
    }
    sort(testcases, testcases + total, cmp_g);
    
    printf("%d\n", total);
    int r = 2;
    for (int q = 0; q < total; q++) {
        if (q == 0) {
            printf("%s %d %d %d\n", testcases[q].regNum, testcases[q].rank_g, 
               testcases[q].loc_n, testcases[q].rank_l);
            continue;
        }
        if (testcases[q].score != testcases[q-1].score) {
            testcases[q].rank_g = r;
        } else {
            testcases[q].rank_g = testcases[q-1].rank_g;
        }
        r++;
        printf("%s %d %d %d\n", testcases[q].regNum, testcases[q].rank_g, 
               testcases[q].loc_n, testcases[q].rank_l);
    }
    return 0;
}