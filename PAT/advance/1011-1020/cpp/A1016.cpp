#include <cstdio>
#include <algorithm>
#include <cstring> 

using namespace std;

int Rates[24] = {0};
struct Records {
    char name[30];
    int month;
    int day;
    int hour;
    int minute;
    int status; // 0: offline, 1:online
} records[1000];

bool cmp (Records r1, Records r2) {
    if (strcmp(r1.name, r2.name) != 0) return strcmp(r1.name, r2.name) < 0;
    else if (r1.month != r2.month) return r1.month < r2.month;
    else if (r1.day != r2.day) return r1.day < r2.day;
    else if (r1.hour != r2.hour) return r1.hour < r2.hour;
    else return r1.minute < r2.minute;
}

int calcAmountFirstNHours(int n) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret += Rates[i] * 60;
    }
    return ret;
} 

int main() {
    // 持续一天打电话花费钱
    int dayAmount = 0;
    for (int i = 0; i < 24; i++) {
        scanf("%d", &Rates[i]);
        dayAmount += Rates[i] * 60;
    }
    
    int n;
    scanf("%d", &n);
    char status[10];
    for (int i = 0; i < n; i++) {
        scanf("%s %02d:%02d:%02d:%02d %s", records[i].name, &records[i].month, &records[i].day, 
              &records[i].hour, &records[i].minute, status);
        if (status[1] == 'n') records[i].status = 1;
        else records[i].status = 0;
    }
    sort(records, records+n, cmp);
    
    int idx = 0;
    int amount = 0;
    int totalAmount = 0;
    int duration = 0;
    int cnt = 0;
    Records preRecord = records[0];
    while (idx < n) {
        // online
        if (records[idx].status == 1 && idx+1 < n && records[idx+1].status == 0 
            && strcmp(records[idx].name, records[idx+1].name) == 0) {
            // 输出姓名与月份以及上一个顾客的总消费
            if (cnt == 0) printf("%s %02d\n", records[idx].name, records[idx].month);
            
            if (cnt != 0 && strcmp(records[idx].name, preRecord.name) != 0) {
                printf("Total amount: $%.2f\n", totalAmount / 100.0);
                printf("%s %02d\n", records[idx].name, records[idx].month);
                totalAmount = 0;
                preRecord = records[idx];
            }
            cnt++;
            
            int j = idx + 1;
            // 天
           amount += 
               dayAmount * (records[j].day - records[idx].day)
                + calcAmountFirstNHours(records[j].hour)- calcAmountFirstNHours(records[idx].hour)
               + Rates[records[j].hour] * records[j].minute - Rates[records[idx].hour] * records[idx].minute;;
            duration += 
                60 * 24 * (records[j].day - records[idx].day) 
                + records[j].hour * 60 - records[idx].hour * 60
                + records[j].minute - records[idx].minute;
            
            totalAmount += amount;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", 
                   records[idx].day, records[idx].hour, records[idx].minute,
                   records[j].day, records[j].hour, records[j].minute,
                   duration, 1.0 * amount / 100);
            amount = 0;
            duration = 0;
            idx += 2;
        } else {
            idx++;
        }
    }
    if (totalAmount != 0)printf("Total amount: $%.2f\n", totalAmount / 100.0);
    return 0;
}