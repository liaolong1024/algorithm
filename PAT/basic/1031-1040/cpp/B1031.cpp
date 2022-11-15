#include <cstdio>

const int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
const char map[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int main() {
    char in[19];
    int n;
    scanf("%d", &n);
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", in);
        int j = 0;
        while (j < 17) {
            if (!(in[j]>='0' && in[j] <= '9')) break;
            sum += (in[j]-'0') * weight[j];
            j++;
        }
        if (j != 17) {printf("%s\n", in);cnt++;}
        else if (in[17] != map[sum%11]) {
            printf("%s\n", in);
            cnt++;
        }
        sum = 0;
    }
    if (cnt == 0)printf("All passed");
    return 0;
}