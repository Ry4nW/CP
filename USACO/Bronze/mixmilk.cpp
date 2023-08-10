#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("mixmilk");
    vector<int> c(3);
    vector<int> a(3);
    for (int i = 0; i < 3; ++i) { cin >> c[i] >> a[i]; }

    for (int i = 0; i < 33; ++i) {
        for (int j = 0; j < 3; ++j) {
            int next = j == 2 ? 0 : j + 1;
            int min_dif = min(c[next] - a[next], a[j]);
            a[next] += min_dif;
            a[j] -= min_dif;
        }
    };

    int last_min_dif = min(c[1] - a[1], a[0]);
    a[1] += last_min_dif;
    a[0] -= last_min_dif;

    for (int i : a) cout << i << '\n';

    return 0;
}
