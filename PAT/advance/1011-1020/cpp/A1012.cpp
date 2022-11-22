#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
/**
  该题题意是输出每位学生成绩最好的排名以及对应分数类别, 分数类别不是输出学生四种分数中最好成绩的那个, 而是排名最好的那个 

*/
struct Student {
    int id;
    int grade[4];
} stu[2010];

char course[4] = {'A', 'C', 'M', 'E'};
// id -> 分数种类
int ranks[1000000][4] = {0};
int now;

bool cmp(Student a, Student b) {
    return a.grade[now] > b.grade[now];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0) + 0.5;
    }
    // 单独根据4种分数给她们排名
    for (now = 0; now < 4; now++) {
        sort(stu, stu+n, cmp);
        // now科目分数第一
        ranks[stu[0].id][now] = 1;
        for (int i = 1; i < n; i++) {
            if (stu[i].grade[now] == stu[i-1].grade[now]) {
                ranks[stu[i].id][now] = ranks[stu[i-1].id][now];
            } else {
                ranks[stu[i].id][now] = i+1;
            }
        }
    }
    int id;
    for (int i = 0; i < m; i++) {
        scanf("%d", &id);
        if (ranks[id][0] == 0) printf("N/A\n");
        else {
            int k = 0;
            for (int j = 0; j < 4; j++) {
                if (ranks[id][j] < ranks[id][k]) {
                    k = j; 
                }
            }
            printf("%d %c\n", ranks[id][k], course[k]);
        }
    }
    return 0;
}