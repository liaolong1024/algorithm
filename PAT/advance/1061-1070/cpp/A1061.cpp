#include <cstdio>
#include <cstring>

const char week[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    char a[70], b[70], c[70], d[70];
    scanf("%s%s%s%s", a, b, c, d);
    // a b 周几与小时
    int cnt = 0;
    bool flag = true;
    int hour;
    for (int i = 0; i < strlen(a) && i < strlen(b); i++) {
        if (a[i] == b[i]) {
                        
            if (flag && a[i] >= 'A' && a[i] <= 'G') {
                printf("%s ", week[a[i]-'A']);
                flag = false;
                continue;
            }
            if (!flag && a[i] >= 'A' && a[i] <= 'N') {
                hour = a[i] - 'A' + 10;
                break;
            }
            if (!flag && a[i] >= '0' && a[i] <= '9') {
                hour = a[i] - '0';
                break;
            }

        }
    }
    // c d之间找分钟
    int minute;
    for (int i = 0; i < strlen(c) && i < strlen(d); i++) {
        if (c[i] == d[i] && ((c[i] >= 'a' && c[i] <= 'z') || c[i] >= 'A' && c[i] <= 'Z')) {
            minute = i;
            break;
        }
    }
    printf("%02d:%02d", hour, minute);
    return 0;
}