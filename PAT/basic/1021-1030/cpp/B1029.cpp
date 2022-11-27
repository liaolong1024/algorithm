#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string in;
    string out;
    map<char, int> m;
    cin >> in >> out;
    for (int i = 0; i < out.length(); i++) {
        char c = out[i];
        if (c >= 'a' && c <= 'z') c -= 32;
        m[c] = i;
    }
    for (int i = 0; i < in.length(); i++) {
        char c = in[i];
        if (c >= 'a' && c <= 'z') c -= 32;
        if (m.find(c) == m.end()) {
            m[c] = i;
            cout << c;
        }
    }
}