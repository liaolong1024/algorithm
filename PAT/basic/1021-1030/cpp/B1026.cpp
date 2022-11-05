#include <cstdio>

const int CLK_TK = 100;

int main() {
    int c1, c2;
    scanf("%d%d", &c1, &c2);
    int cnt = c2 - c1;
    int second;
    if (cnt % 100 >= 50) {
        second = cnt / 100 + 1;
    } else {
        second = cnt / 100;
    }
    printf("%02d:%02d:%02d", second / 3600, second % 3600 / 60, second % 60);
    return 0;
}