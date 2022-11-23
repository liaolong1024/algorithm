#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    char name[10];
    int grade;
} students[100000];

bool cmpById(Student s1, Student s2) {
    return s1.id < s2.id;
}

bool cmpByName(Student s1, Student s2) {
    if (strcmp(s1.name, s2.name) != 0) return strcmp(s1.name, s2.name) < 0;
    else return cmpById(s1, s2);
}

bool cmpByGrade(Student s1, Student s2) {
    if (s1.grade != s2.grade) return s1.grade < s2.grade;
    else return cmpById(s1, s2);
}

int main() {
    int n, c;
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%06d%s%d", &students[i].id, students[i].name, &students[i].grade);
    }
    if (c == 1) {
        sort(students, students+n, cmpById);
    } else if (c == 2) {
        sort(students, students+n, cmpByName);
    } else if (c == 3) {
        sort(students, students+n, cmpByGrade);
    }
    for (int i = 0; i < n; i++) {
        printf("%06d %s %d\n", students[i].id, students[i].name, students[i].grade);
    }
    return 0;
}