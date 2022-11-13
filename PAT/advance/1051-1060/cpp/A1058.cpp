#include <cstdio>

struct money {
    int g;
    int s;
    int k;
} A, B;

money add(money m1, money m2) {
    money sum;
    sum.g = m1.g + m2.g;
    sum.s = m1.s + m2.s;
    sum.k = m1.k + m2.k;
    sum.s += sum.k / 29;
    sum.k = sum.k % 29;
    sum.g += sum.s / 17;
    sum.s = sum.s % 17;
    return sum;
}

int main() {
    scanf("%d.%d.%d %d.%d.%d", &A.g, &A.s, &A.k, &B.g, &B.s, &B.k);
    money sum = add(A, B);
    printf("%d.%d.%d", sum.g, sum.s, sum.k);
    return 0;
}