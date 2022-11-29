#include <cstdio>
#include <cstring>
int main() {
    char str[10001];
    scanf("%s", str);
    int cnt[6] = {0};
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'P') {
            cnt[0] += 1;
        } else if (str[i] == 'A') {
            cnt[1] += 1;
        } else if (str[i] == 'T') {
            cnt[2] += 1;
        } else if (str[i] == 'e') {
            cnt[3] += 1;
        } else if (str[i] == 's') {
            cnt[4] += 1;
        } else if (str[i] == 't') {
            cnt[5] += 1;
        } else {}
    }
    while (true){
        if (cnt[0] > 0) {
            printf("P");
            cnt[0] -= 1;
        }
        if (cnt[1] > 0) {
            printf("A");
            cnt[1] -= 1;
        }
        if (cnt[2] > 0) {
            printf("T");
            cnt[2] -= 1;
        }
        if (cnt[3] > 0) {
            printf("e");
            cnt[3] -= 1;
        }
        if (cnt[4] > 0) {
            printf("s");
            cnt[4] -= 1;
        }
        if (cnt[5] > 0) {
            printf("t");
            cnt[5] -= 1;
        }
        if (cnt[0] == 0 && cnt[0] == cnt[1] && cnt[1] == cnt[2] && cnt[3] ==cnt[4] && cnt[4] == cnt[5]) {
            break;
        }
    }
    return 0;
}