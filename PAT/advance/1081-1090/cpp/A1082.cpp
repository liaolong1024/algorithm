#include <iostream>
using namespace std;


const char ch1[15][6] = {"", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi"};
const char ch2[5][6] = {"", "Shi", "Bai", "Qian"};


int main() {
    string s;
    getline(cin, s);
    int part[3] = {0};
    int numbers = s.length();
    
    // 如果是负数输出负数, 并截取后面的数字部分
    if (s[0]=='-') {
        cout << "Fu ";
        s = s.substr(1, s.length());
        numbers--;
    }
    
    // 如果是零, 直接输出并返回结束程序
    if (s[0]=='0') {
        cout << "ling";
        return 0;
    }
    
    // part数组, 0-2分别是 [亿级部分, 万级部分, 千级部分]
    // 数字字符串分成三组, 每组最多四个数字 记录各部分的数字的个数
    int i = 2;
    while (numbers > 0 && i>=0) {
        part[i] = numbers > 4 ? 4 : numbers;
        numbers -= 4;
        i--;
    }
    
    // 数字字符串截取的起始下标
    int start = 0;
    // 临时字符串, 用于临时保存当前处理的部分字符串
    string tmp;
    // 统计每部分的零的个数, 统计前需要清零
    int zeroCnt = 0;
    for (int j = 0; j < 3; j++) {
        int partN = part[j];
        if (partN != 0) {
           // tmp是第j部分的数字字符串, 长度为partN; 
           tmp = s.substr(start, start+partN);
           for (int k = 0; k < partN; k++) {
               char c = tmp[k];
               // 当时字符是零的时候是不需要输出任何信息, 除非在该部分在这个零之后有非零数字
               if (c == '0') {
                   zeroCnt++;
               } else {
                  // 该非零数之前有前导零,则需要输出" ling"
                   if (zeroCnt > 0) cout << " ling";
                   zeroCnt = 0;
                   // 不是第一个数字则输出前导空格
                   if (start+k!=0)cout << " ";
                   // 输出数字
                   cout << ch1[c-'0'];
                   // 输出数字与单位之间的空格
                   if (k+1 < partN) cout << " ";
                   // 输出单位
                   cout << ch2[partN-1-k];
               }
   
           }
           // 亿万级部分添加Yi wan
           if (j==0) {
              cout << " Yi";
           } else if (j == 1) {
               cout << " Wan";
           }
           zeroCnt = 0;
           start += partN;
        }
    }
    return 0;
}