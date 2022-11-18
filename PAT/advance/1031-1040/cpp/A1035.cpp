#include <cstdio>
#include <cstring>

struct user {
    char uname[15];
    char pwd[15];
};
int main() {
    int n;
    user users[1000];
    
    scanf("%d", &n);
    int m = 0;
    bool modified = false;
    
    for (int i = 0; i < n; i++) {
        user u;
        scanf("%s %s", u.uname, u.pwd);
        for (int j = 0; j < strlen(u.pwd); j++) {
            switch(u.pwd[j]) {
                case '0': u.pwd[j] = '%';modified=true;break;
                case '1': u.pwd[j] = '@';modified=true;break;
                case 'l': u.pwd[j] = 'L';modified=true;break;
                case 'O': u.pwd[j] = 'o';modified=true;break;
                default: break;
            }
        }
        if (modified) {
            users[m] = u;
            m++;
            modified = false;
        }
    }
    if (m == 0) {
        if (n == 1) printf("There is 1 account and no account is modified");
        else printf("There are %d accounts and no account is modified", n);
    } else {
        printf("%d\n", m);
        for (int i = 0; i < m; i++) {
            printf("%s %s\n", users[i].uname, users[i].pwd);
        }
    }
    return 0;
}