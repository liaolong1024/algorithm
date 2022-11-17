#include <cstdio>
#include <cstring>

int main() {
  
    char a[10000];
    scanf("%s", a);
    bool negetive = a[0] == '-' ? true : false ;
    int idx = 1;
    while (a[idx++] != 'E');
    int e = idx-1;
    bool right = a[idx] == '+' ? true : false;
    int stepCnt = 0;
    idx++;
    while (idx < strlen(a)) {
        stepCnt = stepCnt * 10 + a[idx] - '0';
        idx++;
    }


    if (negetive) printf("-");
    idx = 1;
    if (right) {
        printf("%c", a[idx]);
        idx += 2;
        while (stepCnt >= 0 || idx < e) {
            if (stepCnt == 0 && idx < e) {
                printf(".");
            } else if (idx < e) {
                printf("%c", a[idx++]);
            } else if (stepCnt > 0) {
                printf("0");
            }
            stepCnt--;
        }
    } else {
        printf("0.");
        for (int i = 0; i < stepCnt-1; i++){
            printf("0");
        }
        printf("%c", a[idx]);
        idx += 2;
        while (idx < e) {
            printf("%c", a[idx++]);
        }
    }
    return 0;
}