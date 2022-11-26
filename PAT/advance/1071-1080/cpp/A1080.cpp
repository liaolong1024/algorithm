#include <cstdio>
#include <algorithm>
using namespace std;
struct Applicant {
    int id;
    int ge;
    int gi;
    int total;
    int rank;
    int choices[100];
} applicants[40000];

struct School {
    int id;
    int quota;
    Applicant admints[40000];
    int cnt;
}sch[100];

bool cmpByScore(Applicant a, Applicant b) {
    if (a.total != b.total) return a.total > b.total;
    else return a.ge > b.ge;
}

bool cmpById(Applicant a, Applicant b) {
    return a.id < b.id;
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d", &sch[i].quota);
        sch[i].cnt = 0;
        sch[i].id = i;
    }
    for (int i = 0; i < n; i++) {
        applicants[i].id = i;
        scanf("%d%d", &applicants[i].ge, &applicants[i].gi);
        applicants[i].total = applicants[i].ge + applicants[i].gi;
        for (int j = 0; j < k; j++) {
            scanf("%d", &applicants[i].choices[j]);
        }
    }
    sort(applicants, applicants+n, cmpByScore);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int c = applicants[i].choices[j];
            int next = sch[c].cnt;
            if (sch[c].quota != 0) {
                sch[c].admints[next] = applicants[i];
                sch[c].cnt = next+1;
                sch[c].quota--;
                break;
            } else {
                if (next > 0 
                 && sch[c].admints[next-1].total == applicants[i].total 
                 && sch[c].admints[next-1].ge == applicants[i].ge) {
                    sch[c].admints[next] = applicants[i];
                    sch[c].cnt = next+1;
                    break;
                }
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        int cnt = sch[i].cnt;
        sort(sch[i].admints, sch[i].admints + cnt, cmpById);
        for (int j = 0; j < cnt; j++) {
            printf("%d", sch[i].admints[j].id);
            if (j!=cnt-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}

