#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main() {
    string in;
    getline(cin, in);
    int hashtable[27] = {0};
    for (int i = 0; i < in.length(); i++) {
        if (in[i] >= 'a' && in[i] <= 'z') {
            hashtable[in[i]-'a'] += 1;
        }
        if (in[i] >= 'A' && in[i] <= 'Z') {
            hashtable[in[i]-'A'] += 1;
        }
    }
    int max = 0, idx;
    for (int i = 0; i < 26; i++) {
        if (max < hashtable[i]) {
            max = hashtable[i];
            idx = i;
        }
    }
    printf("%c %d", 'a' + idx, max);
    return 0;
}