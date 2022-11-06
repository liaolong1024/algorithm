#include <cstdio>

int main() {
    long long t, a, b, c;
    scanf("%lld", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        long long sum = a + b;
        bool flag;
        if (a >= 0 && b >= 0 && sum < 0) {
            flag = true;
        } else if (a <= 0 && b <=0 && sum >= 0) {
            flag = false;
        } else if (sum > c) {
            flag = true;
        }else {
            flag = false;
        }
        if (flag) {
            printf("Case #%d: true\n", i);
        } else {    
            printf("Case #%d: false\n", i);
        }
    }
    
    return 0;
}