#include <cstdio>

int main() {
    int cnt = 0;
    char ans[100][100];
    while (scanf("%s", ans[cnt]) != EOF) cnt++;
    for (int i = cnt - 1; i >= 0; i--) {
        printf("%s", ans[i]);
        if (i != 0) printf(" ");
    }
    return 0;
}