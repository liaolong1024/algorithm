#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int n;
    int scores[101] = {0};
    memset(scores, 0, 101);
    scanf("%d", &n);
    int score;
    for (int i = 0; i < n; i++) {
        scanf("%d", &score);
        scores[score] += 1;
    }
    int k, query;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &query);
        printf("%d", scores[query]);
        if (i != k-1)printf(" ");
    }
    return 0;
}