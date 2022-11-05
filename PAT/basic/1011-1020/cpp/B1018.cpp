#include <cstdio>

void calc(int resWin[], int resFail[]) {
    resWin[0] = resWin[0] + 1;
    resFail[2] = resFail[2] + 1;
} 

int main() {
    int n;
    char a, b;
    int winA[3] = {0}, resA[3] = {0}, winB[3] = {0}, resB[3] = {0};
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c %c", &a,&b);
        if (a == b) {
            resA[1] = resA[1] + 1;
            resB[1] = resB[1] + 1;
            continue;
        }
        if (a == 'C') {
            if (b == 'J') {
                calc(resA, resB);
                winA[1] = winA[1] + 1;
            } else {
                calc(resB, resA);
                winB[0] = winB[0] + 1;
            }
        }
        if (a == 'J') {
            if (b == 'B') {
                calc(resA, resB);
                winA[2] = winA[2] + 1;
            } else {
                calc(resB, resA);
                winB[1] = winB[1] + 1;
            }
        }
        if (a == 'B') {
            if (b == 'C') {
                calc(resA, resB);
                winA[0] = winA[0] + 1;
            } else {
                calc(resB, resA);
                winB[2] = winB[2] + 1;
            }
        }
    }
    
    for (int i = 0; i < 3; i++) {
        printf("%d", resA[i]);
        if (i == 2) printf("\n");
        else printf(" ");
    }
    for (int i = 0; i < 3; i++) {
        printf("%d", resB[i]);
        if (i == 2) printf("\n");
        else printf(" ");
    }
    
    int max = -1;
    int maxIndex = -1;
    for (int i = 0; i < 3; i++) {
        if (max < winA[i]) {
            max = winA[i];
            maxIndex = i;
        }
    }
    printf("%c ", maxIndex==0 ? 'B' : (maxIndex == 1 ? 'C': 'J'));
    
    max = -1;
    maxIndex = -1;
    for (int i = 0; i < 3; i++) {
        if (max < winB[i]) {
            max = winB[i];
            maxIndex = i;
        }
    }
    printf("%c", maxIndex==0 ? 'B' : (maxIndex == 1 ? 'C': 'J'));
    return 0;
}