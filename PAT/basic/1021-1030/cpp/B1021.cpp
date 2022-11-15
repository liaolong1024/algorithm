#include <cstdio>

int main() {
    char in[1001];
    int cnt[10] = {0};
    scanf("%s", in);
    int idx = 0;
    while (in[idx] != '\0') {
        cnt[in[idx]-'0'] += 1;
        idx++;
    }
    for (int i = 0; i < 10; i++) {
        if (cnt[i] != 0) {
            printf("%d:%d\n", i, cnt[i]);
        }
    }
    return 0;
}