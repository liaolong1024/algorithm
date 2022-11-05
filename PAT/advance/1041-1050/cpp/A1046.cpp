#include <cstdio>
#include <algorithm>
using namespace std;

const int maxN = 1e5 + 1;
const int maxM = 1e4 + 1;

int main() {
    int n, m, sum = 0;
    // i --> i+1  distance 
    int dis[maxN];
    // 1 --> i+1  distance,  d(posA --> posB) = dFrom0[posB-1] - dFromPos[posA-1]
    int dFrom0[maxN] = {0};
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", dis+i);
        sum += dis[i];
        dFrom0[i] = sum;
    }
    scanf("%d",&m);
    
    int a, b, d;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        if (a > b) swap(a, b);
        d = dFrom0[b-1] - dFrom0[a-1];
        printf("%d\n", min(d, sum - d));
    }
    
    return 0;
}