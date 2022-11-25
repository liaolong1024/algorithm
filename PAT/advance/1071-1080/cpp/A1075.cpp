#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

struct User {
    int id;
    int score[6];
    int solved;
    int submit_suc;
    int totalScore;
    int rank;
} users[10000];

bool cmp(User u1, User u2) {
    if (u1.totalScore != u2.totalScore) return u1.totalScore > u2.totalScore;
    else if (u1.solved != u2.solved) return u1.solved > u2.solved;
    else return u1.id < u2.id;
}

int n, k, m;

void init() {
    for (int i = 1; i <= n; i++) {
        users[i].id = i;
        users[i].totalScore = 0;
        users[i].submit_suc = 0;
        users[i].solved = 0;
        memset(users[i].score, -1, sizeof(users[i].score));
    }
}

int main()  {
    int fullMark[6];
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &fullMark[i]);
    }
    init();
    
    int id;
    int pid;
    int score;
    for (int i = 0; i < m; i++) {
        scanf("%05d%d%d", &id, &pid, &score);
        if (users[id].score[pid] == -1) {
            users[id].id = id;
            if (score == -1) {
                users[id].score[pid] = 0;
            } else {
                users[id].score[pid] = score;
            }
            
            if (score >= 0) {
                users[id].totalScore += score;
                users[id].submit_suc += 1;
                if (score == fullMark[pid]) {
                    users[id].solved += 1;
                }
            }
        } else {
            if (users[id].score[pid] < score) {
                if (score >= 0) {
                    int old = users[id].score[pid];
                    users[id].totalScore += score - old;
                    if(old == 0) users[id].submit_suc += 1;
                    if (score == fullMark[pid]) {
                        users[id].solved += 1;
                    }
                }
                users[id].score[pid] = score;
                
            }
        }
    }
    sort(users+1, users+n+1, cmp);
    
    
    users[1].rank = 1;
    printf("%d %05d %d", users[1].rank, users[1].id, users[1].totalScore);
    for (int j = 1; j <= k; j++) {
        if (users[1].score[j] == -1) printf(" -");
        else printf(" %d", users[1].score[j]);
    }
    printf("\n");
    int r = 1;
    for (int i = 2; i <= n; i++) {
        if (users[i].submit_suc == 0)continue;
        if (users[i].totalScore != users[i-1].totalScore) {
            users[i].rank = r+1;
        } else {
            users[i].rank = users[i-1].rank;
        }
        r++;
        
        printf("%d %05d %d", users[i].rank, users[i].id, users[i].totalScore);
        for (int j = 1; j <= k; j++) {
            if (users[i].score[j] == -1) printf(" -");
            else printf(" %d", users[i].score[j]);
        }
        printf("\n");
    }
    return 0;
}