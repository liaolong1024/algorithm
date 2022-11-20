#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    scanf("%d\n", &n);
	  string ans;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        reverse(s.begin(), s.end());
        if (i==0) ans = s;
        int minLen = min(s.length(), ans.length());
        for (int j = 0; j < minLen; j++) {
            if (ans[j] != s[j]) {
                ans = ans.substr(0, j);
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    if (ans.length()==0) ans = "nai";
    cout << ans;
    return 0;
}