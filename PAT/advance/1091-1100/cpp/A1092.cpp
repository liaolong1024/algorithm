#include <iostream>
#include <map>
using namespace std;

int main() {
    string shop, eva;
    map<char, int> mp;
    cin >> shop >> eva;
    int shoplen = shop.length();
    for (int i = 0; i < shoplen; i++) {
        auto it = mp.find(shop[i]);
        if (it == mp.end()) {
            mp[shop[i]] = 1;
        } else {
            it->second += 1;
        }
    } 
    int evalen = eva.length();
    int lack = 0;
    for (int i = 0; i < evalen; i++) {
        auto it = mp.find(eva[i]);
        if (it == mp.end() || it->second == 0) {
            lack++;
        } else {
            it->second -= 1;
        }
    }
    if (lack == 0) {
        printf("Yes %d", shoplen-evalen);
    } else {
        printf("No %d", lack);
    }
    return 0;
}