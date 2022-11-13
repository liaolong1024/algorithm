#include <cstdio>

const char radix13[] = {'0', '1', '2','3','4','5','6','7','8','9','A','B','C'};
const int radix = 13;

int convert(char color[], int decimal) {
    int cnt = 0;
    do {
        color[cnt++] = radix13[decimal % radix];
        decimal /= radix;
    } while (decimal != 0);
    return cnt;
}
void print(char color[], int size) {
    for (int i = 0; i < 2-size; i++) {
        printf("0");
    }
    for (int i = size - 1; i >= 0; i--) {
        printf("%c", color[i]);
    }
}
int main() {
    int r, g, b;
    scanf("%d%d%d", &r,&g, &b);
    char marsR[2], marsG[2], marsB[2];
    int sizeR = convert(marsR, r);
    int sizeG = convert(marsG, g);
    int sizeB = convert(marsB, b);
    printf("#");
    print(marsR, sizeR);
    print(marsG, sizeG);
    print(marsB, sizeB);
    
    return 0;
}