#include <cstdio>

int main() {
    int nums[1010] = {0};
    int a, b, cnt = 0;
    while (scanf("%d%d", &a, &b) != EOF) {
        nums[cnt] = a;
        nums[cnt+1] = b;
        cnt += 2;
    }
    
    int cnt0 = 0;
    for (int i = 0; i < cnt; i += 2) {
        nums[i] = nums[i] * nums[i+1];
        if (nums[i+1] == 0) {
            nums[i+1] = 0;
        } else {
            nums[i+1] = nums[i+1] - 1;
        }
        if (nums[i] != 0) {
            cnt0++;
        }
    }
    int j = 0, k = 0;
    // 求导之后是0, 要输出0 0 (好坑!!)
    if (cnt0 == 0) printf("0 0");
    else {
        while (j < cnt0) {
            if (nums[k] == 0 && nums[k+1] == 0) {
                k += 2;
                continue;
            } else {
                printf("%d %d", nums[k], nums[k+1]);
                j++;
                k += 2;
            }
            if (j < cnt0) {
                printf(" ");
            }
        }
    }

    
}