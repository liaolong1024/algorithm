#include <cstdio>

int main() {
    int k;
    double coutSum[1001] = {0.0};
    int e, cntSum = 0;
    double c;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &e);
        scanf("%lf", &c);
        coutSum[e] += c;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &e);
        scanf("%lf", &c);
        coutSum[e] += c;
    }
    for (int i = 0; i < 1001; i++) {
        if (coutSum[i] != 0.0) {
            cntSum++;
        }
    }
    printf("%d", cntSum);
    for (int i = 1000; i >= 0 && cntSum > 0; i--) {
        if (coutSum[i] != 0) {
            printf(" %d %.1f", i, coutSum[i]);
            cntSum--;
        }
    }
}