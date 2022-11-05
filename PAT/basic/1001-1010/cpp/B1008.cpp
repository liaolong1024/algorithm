#include <cstdio>

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int n, m;
    int nums[100] = {0};
    
    scanf("%d%d", &n,&m);
    for (int i = 0; i < n; i++) {
        scanf("%d", nums + i);
    }
    
    m %= n;
    if (m != 0) {
        
        for (int i = n-m; i < n-m + gcd(n,m); i++) {
            int from = i-m < 0 ? i-m+n : i-m;
            int tempIdx = i, tempVal = nums[i];
            while (from != i) {
                nums[tempIdx] = nums[from];
                tempIdx = from;
                from = from-m < 0 ? from-m+n : from-m;
            }
            nums[tempIdx] = tempVal;
        }
    } 
    
    
    for (int i = 0; i < n; i++) {
        printf("%d", nums[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
}