#include <cstdio>

struct stu {
    char name[11];
    char gender;
    char id[11];
    int score;
} high, low;

void init() {
    high.gender = 'F';
    high.score = -1;
    low.gender = 'M';
    low.score = 101;
}
int main() {
    init();
    
    int n;
    stu tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %c %s %d", tmp.name, &tmp.gender, tmp.id, &tmp.score);
        if (tmp.gender == 'F' && tmp.score > high.score) {
            high = tmp;
        }
        if (tmp.gender == 'M' && tmp.score < low.score) {
            low = tmp;
        }
    }
    
    bool flag = false;
    if (high.score < 0) {
        printf("Absent\n");
        flag = true;
    } else {
        printf("%s %s\n", high.name, high.id);
    }
    if (low.score > 100) {
        flag = true;
        printf("Absent\n");
    } else {
        printf("%s %s\n", low.name, low.id);
    }
    if (flag) printf("NA\n");
    else printf("%d\n", high.score - low.score);
}