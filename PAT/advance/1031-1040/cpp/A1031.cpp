#include <cstdio>
#include <cstring>

int main() {
    int n1, n2, n3;
    char str[100];
    scanf("%s", str);
    int len = strlen(str);
    n2 = (len + 2) / 3 + (len + 2) % 3;
    n1 = n3 = (len - n2 + 2) / 2;
    for (int i = 0; i < n1 - 1; i++) {
        printf("%c", str[i]);
        for (int j = 0; j < n2 - 2; j++) {
            printf(" ");
        }
        printf("%c\n", str[len-1-i]);
    }
    for (int i = n1 - 1; i < n1 - 1 + n2; i++) {
        printf("%c", str[i]);
    }
    return 0;
}