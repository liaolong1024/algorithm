#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Man {
    int type;
    char id[10];
    int t;
    int v;
    int r;
} testcases[100000];

bool cmp (Man m1, Man m2) {
    if (m1.type != m2.type) return m1.type < m2.type;
    else if (m1.t + m1.v != m2.t + m2.v) return m1.t + m1.v > m2.t + m2.v;
    else if (m1.v != m2.v) return m1.v > m2.v;
    else return strcmp(m1.id, m2.id) < 0;
}

int main() {
    int n, l, h;  // 均l以下忽略, 均h以上sage
    // 总分数排名(递减)  sage -> noblemen -> fool men -> 其他
    // t below h, v beyound h -> noblemen
    // t,v below h, v > t  -> fool men
    scanf("%d%d%d", &n, &l, &h);
    int total = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s%d%d", testcases[total].id, &testcases[total].v, &testcases[total].t);
        if (testcases[total].v < l || testcases[total].t < l) {
            continue;
        } else if (testcases[total].v >= h && testcases[total].t >= h) {
            testcases[total].type = 1;
        } else if (testcases[total].t < h && testcases[total].v >= h) {
            testcases[total].type = 2;
        } else if (testcases[total].v >= testcases[total].t) {
            testcases[total].type = 3;
        } else {
            testcases[total].type = 4;
        }
        total++;
    }
    sort(testcases, testcases + total, cmp);
    printf("%d\n", total);
    for (int i = 0; i < total; i++) {
        printf("%s %d %d\n", testcases[i].id, testcases[i].v, testcases[i].t);
    }
    return 0;
}