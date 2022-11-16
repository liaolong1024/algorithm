#include <cstdio>
#include <cstring>

const char number[10][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
    char in[101];
    scanf("%s", in);
    int sum = 0;
    for (int i = 0; i < strlen(in); i++) {
        sum += in[i] - '0';
    }
    char out[10][10];
    int cnt = 0;
    do {
        sprintf(out[cnt],"%s", number[sum%10]);
        sum /= 10;
        cnt++;
    } while (sum != 0);
    
    for (int i = cnt - 1; i >= 0; i--) {
        printf("%s", out[i]);
        if (i != 0) printf(" ");
    }
    return 0;
}