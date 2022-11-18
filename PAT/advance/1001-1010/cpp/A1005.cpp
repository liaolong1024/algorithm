/**
  递归写法
*/

#include <cstdio>
#include <cstring>

const char en[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void print(int n) {
    if (n == 0) return;
    print(n/10);
    if (n > 10)printf(" ");
    printf("%s", en[n%10]);
    
}
int main() {
    char n[110];
    scanf("%s", n);
    int sum = 0;
    for (int i = 0; i < strlen(n); i++) {
        sum += n[i] - '0';
    }
    if (sum==0)printf("%s", en[0]);
    else print(sum);
    return 0;
}