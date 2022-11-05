#include <cstdio>

int main() {
    int n, a1, a2, b1, b2, cntA = 0, cntB = 0;
    scanf("%d", &n);
    while (n-- > 0) {
        scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
        int sum = a1 + b1;
        if ((sum == a2 && sum == b2) || (sum != a2 && sum != b2)) {
            continue;
        } else if (sum == a2) {
            cntB++;
        } else {
            cntA++;
        }
    }
    printf("%d %d", cntA, cntB);
    return 0;
}