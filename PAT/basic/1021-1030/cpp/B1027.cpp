#include <cstdio>
#include <cmath>

int main() {
    int n;
    char c;
    
    scanf("%d %c", &n, &c);
    // 以最中间一行为分界, 上面的行数为x(不包括中间行)
    int x = -1 + sqrt(2*n+2) / 2;
    int space = 0;
    // 上 + 中间星号
    for (int i = 0; i < x+1; i++) {
        for (int j = 0; j < space; j++) {
            printf(" ");
        }
        for (int j = 0; j < 1 + (x-i)*2; j++) {
            printf("%c", c);
        }
        printf("\n");
        space++;
    }
    // 下
    space -= 2;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < space; j++) {
            printf(" ");
        }
        for (int j = 0; j < 3 + i*2; j++) {
            printf("%c", c);
        }
        printf("\n");
        space--;
    }
    printf("%d\n", n - (1+(4+2*x)*x));
    return 0;
}