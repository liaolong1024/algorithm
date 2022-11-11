#include <cstdio>
#include <algorithm>
using namespace std;

struct date {
	int year;
	int month;
	int day;
}a, b;

const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool later (date a, date b) {
	if (a.year != b.year) return a.year > b.year;
	else if (a.month != b.month) return a.month > b.month;
	else return a.day > b.day;
}

bool isLeap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); 
}

// 计算日期差值
int main() {
	scanf("%4d%02d%02d", &a.year, &a.month, &a.day);
	scanf("%4d%02d%02d", &b.year, &b.month, &b.day);
	if (later(a, b)) swap(a, b);
	int dif = 0;
	dif += (b.year - a.year) * 365;
	for (int i = a.year; i < b.year; i++) {
		if (isLeap(i)) 	dif++;
	}
	for (int i = 1; i < a.month; i++) {
		dif -= days[i];
		if (i == 2 && isLeap(a.year)) dif--;
	}
	for (int i = 1; i < b.month; i++) {
		dif += days[i];
		if (i == 2 && isLeap(b.year)) dif++;
	}
	dif += b.day - a.day + 1;
	printf("%d\n", dif);
}