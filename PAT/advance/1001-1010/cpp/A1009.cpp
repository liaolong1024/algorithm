#include <cstdio>

const int maxK = 1001;
const int maxP = 1000 + 1000 + 1;
int main() {
    int k, e, cntA = 0, cntB = 0, cntP = 0;
    double c, a[maxK] = {0}, b[maxK] = {0}, product[maxP] = {0};
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &e);
        scanf("%lf", &c);
        a[e] = c;
        cntA++;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &e);
        scanf("%lf", &c);
        int temp = cntA;
        for (int j = maxK - 1; j >= 0 && temp > 0; j--) {
            if (a[j] != 0) {
                temp--;
                product[e + j] += a[j] * c;
            }
        }
    }
    for (int i = 0; i < maxP; i++) {
        if (product[i] != 0) {
            cntP++;
        }
    }
    printf("%d", cntP);
    for (int i = maxP - 1; i >=0 && cntP > 0; i--) {
        if (product[i] != 0) {
            printf(" %d %.1f", i, product[i]);
            cntP--;
        }
    }
    return 0;
}