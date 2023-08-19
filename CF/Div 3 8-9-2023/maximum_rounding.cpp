#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        string n;
        cin >> n;

        n = '0' + n;

        int k = n.size();
        for (int i = n.size(); i > -1; --i) {
            if (n[i] >= '5') n[i - 1]++, k = i;
        }

        for (int i = (n[0] == '0'); i < n.size(); ++i) {
            cout << (i < k ? n[i] : '0');
        }
        cout << '\n';
    }
    return 0;
}
