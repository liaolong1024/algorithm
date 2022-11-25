#include <cstdio>
#include <algorithm>
using namespace std;
struct Student {
    char name[15];
    char id[15];
    int grade;
}stus[100000];


bool cmp (Student a, Student b) {
    return a.grade > b.grade;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%s%d", stus[i].name, stus[i].id, &stus[i].grade);
    }
    int grade1, grade2;
    scanf("%d%d", &grade1, &grade2);
    sort(stus, stus+n, cmp);
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (stus[i].grade >= grade1 && stus[i].grade <= grade2) {
            cnt++;
            printf("%s %s\n", stus[i].name, stus[i].id);
        }
    }
    if (cnt == 0)printf("NONE");
    return 0;
}