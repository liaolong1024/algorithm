#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct People {
    char name[10];
    int age;
    int worth;
} peoples[100000];

bool cmpByWorth(People p1, People p2) {
    if (p1.worth != p2.worth) return p1.worth > p2.worth;
    else if (p1.age != p2.age) return p1.age < p2.age;
    else return strcmp(p1.name, p2.name) < 0;
}


int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", peoples[i].name, &peoples[i].age, &peoples[i].worth);
    }
    sort(peoples, peoples+n, cmpByWorth);
    
    int m, aMin, aMax;
    for (int i = 0; i < k; i++) {
        scanf("%d%d%d", &m, &aMin, &aMax);
        int start = 0;
        int cnt = 0;
        printf("Case #%d:\n", i+1);
        while (cnt < m && start < n) {
            if (peoples[start].age >= aMin && peoples[start].age <= aMax) {
                printf("%s %d %d\n", peoples[start].name, peoples[start].age, peoples[start].worth);
                cnt++;
            }
            start++;
        }
        
        if (cnt == 0) printf("None\n");
    }
    return 0;
}