#include <cstdio>

struct record {
    char id[16];
    int inhh;
    int inmm;
    int inss;
    int outhh;
    int outmm;
    int outss;
} unlock, lock;

void init() {
    unlock.inhh = 23;
    unlock.inmm = unlock.inss = 59;
    lock.outhh = 0;
    lock.outmm = lock.outss = 0;
}

bool outlater(record r1, record r2) {
    if (r1.outhh != r2.outhh) return r1.outhh > r2.outhh;
    else if (r1.outmm != r2.outmm) return r1.outmm > r2.outmm;
    else if (r1.outss != r2.outss) return r1.outss > r2.outss;
    else return true;
}

bool inearly(record r1, record r2) {
    if (r1.inhh != r2.inhh) return r1.inhh < r2.inhh;
    else if (r1.inmm != r2.inmm) return r1.inmm < r2.inmm;
    else if (r1.inss != r2.inss) return r1.inss < r2.inss;
    else return true;
}

int main() {
    init();
    int n;
    record temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d %d:%d:%d", temp.id, 
              &temp.inhh, &temp.inmm, &temp.inss, 
              &temp.outhh, &temp.outmm, &temp.outss
        );
        if (inearly(temp, unlock)) {
            unlock = temp;
        }
        if (outlater(temp, lock)) {
            lock = temp;
        }
    }
    printf("%s %s", unlock.id, lock.id);
    return 0;
}