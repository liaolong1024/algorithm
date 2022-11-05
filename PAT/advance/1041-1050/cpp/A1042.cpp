#include <cstdio>

int main() {
    int k;
    int shuffle[54];
    scanf("%d", &k);
    char outputChar[54];
    int outputInt[54];
    for (int i = 0; i < 54; i++) {
        scanf("%d", shuffle + i);
    }
    int cnt = k;
    for (int i = 0; i < 54; i++) {
        int index = i;
        while (cnt-- > 0) {
            index = shuffle[index]-1;
        }
        cnt = k;

        if (i < 13) {
            outputChar[index] = 'S';
            
        } else if (i < 26) {
            outputChar[index] = 'H';
        } else if (i < 39) {
            outputChar[index] = 'C';
        } else if (i < 52) {
            outputChar[index] = 'D';
        } else {
            outputChar[index] = 'J';
        }
        outputInt[index] = i % 13 + 1;
    }
    for (int i = 0; i < 54; i++) {
        printf("%c%d", outputChar[i], outputInt[i]);
        if (i != 53) printf(" ");
    }
    
    return 0;
}