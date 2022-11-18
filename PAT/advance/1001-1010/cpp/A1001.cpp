#include <cstdio>
#include <cmath>

void print(int c) {
    if (c == 0) return;
    if (c >= 1000) {
        print(c / 1000);
        printf(",%03d", c % 1000);    
    } else {
        printf("%d", c);
    }
}

int main() {
    int a,b;
    if(scanf("%d%d", &a,&b) == 2);
    int c = a + b;
    if (c < 0) printf("%c",'-');
    if (c == 0) {
        printf("%d",c);
    } else {
        print(abs(c));
    }
    return 0;
}

