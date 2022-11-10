#include <cstdio>

int main() {
    int n;
    char c;
    scanf("%d %c", &n, &c);
    for (int i = 0; i < n; i++) {
        printf("%c", c);
    }
    printf("\n");
    
    int restrows = (n+1) / 2 - 2;
    int spacecols = n - 2;
    for (int i = 0; i < restrows; i++) {
        printf("%c", c);
        for (int j = 0; j < spacecols; j++) {
            printf(" ");
        }
        printf("%c\n", c);
    }
    
    for (int i = 0; i < n; i++) {
        printf("%c", c);
    }
    printf("\n");
    return 0;
}