#include <cstdio>
#include <cmath>
int main() {
    
    
    /*
    A1:  n % 5 == 0 && n % 2 == 0 sum
    A2:  n % 5 == 1 n1 - n2 + n3 ...
    A3:  n % 5 == 2 total
    A4:  n % 5 == 3 avg
    A5:  n % 5 == 4 max
    */
    int n = 0;
    scanf("%d", &n);
    int cntA1=0, cntA2=0, cntA3=0,cntA4=0, cntA5=0;
    int sumA1 = 0, sumA2 = 0, sumA4, maxN = -1;
    bool flagA2 = true;
    int num;
    while (n-- > 0) {
        scanf("%d", &num);
        int r = num % 5;
        switch (r) {
            case 1: cntA2++; num = flagA2 ? num : -num; sumA2 += num; flagA2 = !flagA2; break;
            case 2: cntA3++; break;
            case 3: cntA4++; sumA4 += num; break;
            case 4: cntA5++; maxN = fmax(maxN, num);break;
            default: 
                if (num % 2 == 0){
                    cntA1++;
                    sumA1 += num;
                }
        }
    }
    if (cntA1 > 0) {
        printf("%d ", sumA1);
    } else {
        printf("%c ", 'N');
    }
    if (cntA2 > 0) {
        printf("%d ", sumA2);
    } else {
        printf("%c ", 'N');
    }
    if (cntA3 > 0) {
        printf("%d ", cntA3);
    } else {
        printf("%c ", 'N');
    }
    if (cntA4 > 0) {
        printf("%.1f ", 1.0 * sumA4 / cntA4);
    } else {
        printf("%c ", 'N');
    }
     if (cntA5 > 0) {
        printf("%d", maxN);
    } else {
        printf("%c", 'N');
    }
    
    return 0;
}