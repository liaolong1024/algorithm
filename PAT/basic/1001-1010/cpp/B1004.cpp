#include <cstdio>

struct stu {
    char name[11];
    char id[11];
    int score;
};
int main() {
    int n;
    stu maxS, minS, temp;
    maxS.score = -1;
    minS.score = 101;
    scanf("%d", &n);
    for (int i = 0; i <n; i++) {
        scanf("%s %s %d", temp.name, temp.id, &(temp.score));
        if (temp.score < minS.score) {
            minS = temp;
        }
        if (temp.score > maxS.score) {
            maxS = temp;
        }
    }
    printf("%s %s\n%s %s", maxS.name, maxS.id, minS.name, minS.id);
    return 0;
}