#include <cstdio>

struct stu {
    long long id;
    int test;
    int normal;
};
const int maxN = 1001;
int main() {
    int n, test, normal;
    long long id;
    stu stus[maxN];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%d%d", &id, &test, &normal);
        stus[test].id = id;
        stus[test].test = test;
        stus[test].normal = normal;
    }
    
    int m, target;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &target);
        printf("%lld %d\n", stus[target].id, stus[target].normal);
    }
    return 0;
}