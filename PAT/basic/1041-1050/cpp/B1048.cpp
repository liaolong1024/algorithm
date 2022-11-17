#include <cstdio>
#include <cstring>

const char encode[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
int main() {
    char A[110], B[110];
    scanf("%s %s", A, B);
    int lenA = strlen(A);
    int lenB = strlen(B);
    int pa = 0;
    int pb = 0;
    
    // B与A不等长的时候, 用0补齐后计算....
    if (lenB > lenA) {
        while (lenB-pb != lenA) {
            // 无论奇偶位都是B中的数
            printf("%c", B[pb++]);
        }
    } else {
        while (lenA-pa != lenB) {
            // 偶数位是B-A, 需要特殊处理
            if ((lenA-pa)%2==0) {
                printf("%d", (10-(A[pa]-'0')) % 10);
            } else {
                printf("%c", A[pa]);
            }
            pa++;
        }
    }

    int numA, numB, tmp;
    while (pb < lenB) {
        numA = A[pa] - '0';
        numB = B[pb] - '0';
        if ((lenB-pb)%2 == 0) {
            tmp = numB - numA;
            if (tmp < 0) tmp += 10;
            printf("%d", tmp);
        } else {
            tmp = (numA + numB) % 13;
            printf("%c", encode[tmp]);
        }
        pa++;
        pb++;
    }
    return 0;
}