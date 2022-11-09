#include <cstdio>

struct person {
    char name[6];
    int year;
    int month;
    int day;
}leftP, rightP;

void init() {
    leftP.year = 1814;
    leftP.month = 9;
    leftP.day = 5;
    rightP.year = 2014;
    rightP.month = 9;
    rightP.day = 7;
}

int older(person p1, person p2) {
    if (p1.year < p2.year) {
        return 1;
    } else if (p1.year > p2.year) {
        return -1;
    } else if (p1.month < p2.month){
        return 1;
    } else if (p1.month > p2.month) {
        return -1;
    } else if (p1.day < p2.day) {
        return 1;
    } else if (p1.day > p2.day) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    
    init();
    
    person oldest = rightP;
    person youngest = leftP;
    
    int n, year, month, day, valid = 0;
    person temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d/%02d/%02d", temp.name, &(temp.year), &(temp.month), &(temp.day));
        if (older(temp, leftP) >= 0 || older(temp, rightP) <= 0) {
            continue;
        }
        valid++;
        if (older(temp, oldest) == 1) {
            oldest = temp;
        }
        if (older(youngest, temp) == 1) {
            youngest = temp;
        }
    }
    if (valid > 0) {
        printf("%d %s %s", valid, oldest.name, youngest.name);
    } else {
        printf("0");
    }
    
    return 0;
}