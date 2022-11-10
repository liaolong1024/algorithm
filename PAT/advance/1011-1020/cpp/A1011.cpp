#include <cstdio>

int main() {
    double w, t, l, max = -1, profit = 1;
    char result[3];
    for (int i = 0; i < 3; i++) {
        scanf("%lf%lf%lf", &w, &t, &l);
        max = w;
        if (w > t) {
            if (w > l) {
                // w
                profit *= w;
                result[i] = 'W';
            } else {
                // l
                profit *= l;
                result[i] = 'L';
            }
        } else {
            if (t > l) {
                // t
                profit *= t;
                result[i] = 'T';
            } else {
                // l
                profit *= l;
                result[i] = 'L';
            }
        }
    }
    profit = 2 * (profit * 0.65 - 1);
    printf("%c %c %c %.2f", result[0], result[1], result[2], profit);
}