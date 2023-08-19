// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> instrucs(n);
    for (int i = 0; i < n; ++i) cin >> instrucs[i];

    int sum{};

    for (int mask = 0; mask < (1 << n); ++mask) {
        long long sum_cur_subset{};
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i))
                sum += instrucs[i];
            else
                sum -= instrucs[i];
        }
    }

    if (sum % 360 == 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}
