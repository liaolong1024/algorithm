#include <string>
#include <iostream>
#include <map>
using namespace std;

int main() {
    string broken, in;
    // 使用getline可以读入空行, cin会忽略空行
    getline(cin, broken);
    getline(cin, in);
    map<char, int> mp;
    for (int i = 0; i < broken.length(); i++) {
        mp[broken[i]] = 0;
    }
    string out = "";
    auto up = mp.find('+');
    for (int i = 0; i < in.length(); i++) {
        char c = in[i];
        char f;
        if (c >= 'a' && c <= 'z') {
            f = c-32;
        } else {
            f = in[i];
        }
        auto b = mp.find(f);
        if (b == mp.end()) {
            if (c >= 'A' && c <= 'Z') {
                if (up == mp.end()) {
                    out += c;
                }
            } else {
                out += c;
            }
        }
    }
    cout << out << endl;
    return 0;
}