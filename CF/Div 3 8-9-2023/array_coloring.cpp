#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        int oddcount{};
        for (int j = 0; j < n; ++j) {
            int cur;
            cin >> cur;
            if (cur % 2 != 0) oddcount++;
        }
        if (oddcount % 2 == 0)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}
