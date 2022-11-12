#include <cstdio>

struct money {
    int sign = 1;
    int g;
    int s;
    int k;
} p, a;
const int Galleon = 17 * 29;
const int Sickle = 29;
money subtract(money m1, money m2) {
    int k1 = m1.g * Galleon + m1.s * Sickle + m1.k;
    int k2 = m2.g * Galleon + m2.s * Sickle + m2.k;
    int diff = k1 - k2;
    money ret;
    if (diff < 0) {
        ret.sign = -1;
        diff = -diff;
    }
    ret.g = diff / Galleon;
    ret.s = diff % Galleon / Sickle;
    ret.k = diff % Galleon % Sickle; 
    return ret;
}
int main() {
    scanf("%d.%d.%d %d.%d.%d", &p.g, &p.s, &p.k, &a.g, &a.s, &a.k);
    money back = subtract(a, p);
    if (back.sign < 0) printf("-"); 
    printf("%d.%d.%d", back.g, back.s, back.k);
    return 0;
}