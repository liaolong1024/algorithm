#include <cstdio>

void print(char c, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", c);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    print('B', n / 100);
    print('S', n % 100 / 10);
    for (int i = 1; i <= n % 100 % 10; i++) {
        printf("%d", i);
    }
    return 0;
}