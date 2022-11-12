#include <cstdio>

bool isPalindromic(int baseb[], int size, int base) {
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        if (baseb[i] != baseb[j]) return false;
    }
    return true;
}

int main() {
    int baseb[32] = {0};
    int n, base;
    scanf("%d%d", &n, &base);
    int cnt = 0;
    do {
        baseb[cnt++] = n % base;
        n /= base;
    } while (n != 0);
    bool flag = isPalindromic(baseb, cnt, base);
    if (flag)printf("Yes\n");
    else printf("No\n");
    for (int i = cnt-1; i >= 0; i--) {
        printf("%d", baseb[i]);
        if (i != 0) printf(" ");
    }
    return 0;
}