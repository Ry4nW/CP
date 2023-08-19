#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int S;
    cin >> n >> S;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int mask = 0; mask < (1 << n); mask++) {
        long long sum_of_this_subset = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum_of_this_subset += a[i];
            }
        }
        if (sum_of_this_subset == S) {
            cout << "YES" << '\n';
            return 0;
        }
    }

    cout << "NO" << '\n';
    return 0;
}
