#include <cstdio>

int getPx(int n, int dx) {
    int px = 0;
    while (n != 0) {
        if (n % 10 == dx) {
            px = px * 10 + dx;
        }
        n /= 10;
    }
    return px;
} 

int main() {
    int a, da, b, db, pa, pb;
    scanf("%d%d%d%d", &a, &da, &b, &db);
    pa = getPx(a, da);
    pb = getPx(b, db);
    printf("%d", pa + pb);
}