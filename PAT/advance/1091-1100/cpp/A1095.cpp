#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Record {
    char pn[8];
    int seconds;
    int status;
} records[10000];

struct InOut {
    int in;
    int out;
} inout[10000];

// 按id, 时间排序
bool cmp(Record a, Record b) {
    if (strcmp(a.pn, b.pn) != 0) {
        return strcmp(a.pn, b.pn) < 0;
    } else {
        return a.seconds < b.seconds;
    }
}

bool cmpByOut(InOut a, InOut b) {
    return a.out < b.out;
}

/**
  该题未通过
*/
int main() {
    
    int n, k;
    scanf("%d%d", &n, &k);
    
    int hour;
    int minute;
    int second;
    char status[4];
    for (int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d %s", records[i].pn, &hour, &minute, &second, status);
        if (status[0] == 'i') {
            records[i].status = 0;
        } else {
            records[i].status = 1;
        }
        records[i].seconds = hour*3600 + minute*60 + second;
    }
    
    sort(records, records + n, cmp);
    // 1. 或许应该在排好序之后, 先将in out对 筛选出来, 一对集结成一个结构体, 
    // 记录必要的信息(in时间(秒), out时间(秒), 时间间隔(秒), id), 并记录最长时间间隔
    int inoutCnt = 0;
    Record longParked[10000];
    int longCnt = 0;
    int longCntStart = -1;
    int maxDuration = 0;
    for (int i = 0; i < n; i++) {
        if (i+1 < n && records[i].status == 0 && records[i+1].status == 1 && strcmp(records[i].pn, records[i+1].pn) == 0) {
            inout[inoutCnt].in = records[i].seconds;
            inout[inoutCnt].out = records[i+1].seconds;
            inoutCnt++;
            
            int duration = records[i+1].seconds - records[i].seconds;
            if (longCnt > 0 && strcmp(longParked[longCnt-1].pn, records[i].pn) == 0) {
                duration += maxDuration;
            } 
            if (maxDuration <= duration) {
                if (maxDuration != duration) {
                    longCntStart++;
                }
                maxDuration = duration;
                longParked[longCnt++] = records[i];
            }
            i++;
        }
        
    }
    // 2. 按out时间升序排序, 每查询完一次, 都要记录out时间不符合要求的最大元素, 下一次查询, 该下标以及之前的元素都不需要遍历了
    sort(inout, inout+inoutCnt, cmpByOut);
    int start = 0;
    int parkCnt = 0;
    for (int i = 0; i < k; i++) {
        scanf("%02d:%02d:%02d", &hour, &minute, &second);
        int seconds = hour*3600 + minute*60 + second;
        for (int j = start; j < inoutCnt; j++) {
            if (inout[j].out <= seconds) {
                start = j+1;
            } else if (inout[j].in <= seconds) {
                parkCnt++; 
            } else {
                continue;
            }
        }
        printf("%d\n", parkCnt);
        parkCnt = 0;
    }
    
    for (int i = longCntStart; i < longCnt; i++) {
        printf("%s ", longParked[i].pn);
    }
    printf("%02d:%02d:%02d", maxDuration/3600, maxDuration%3600/60, maxDuration%60);
  
}