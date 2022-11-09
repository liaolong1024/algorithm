#include <cstdio>

const int maxN = 1e5 + 1;
int scores[maxN] = {0};

int main() {
    int n, schID, score, maxTotal = 0, maxSchID;
    scanf("%d", &n);
    while (n > 0) {
        scanf("%d%d", &schID, &score);
        scores[schID] += score;
        if (scores[schID] >= maxTotal) {
            maxTotal = scores[schID];
            maxSchID = schID;
        }
        n--;
    }
    printf("%d %d", maxSchID, maxTotal);
}