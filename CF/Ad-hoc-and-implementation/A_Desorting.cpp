#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        vector<int> cur(n);
        for (int j = 0; j < n; ++j) cin >> cur[j];
        vector<int> cur_sorted = cur;
        sort(cur_sorted.begin(), cur_sorted.end());
        if (cur != cur_sorted) {
            cout << 0 << '\n';
            continue;
        }

        int max_dif = numeric_limits<int>::max();
        for (int j = 1; j < n; ++j) {
            max_dif = min(max_dif, cur[j] - cur[j - 1]); 
        }
        cout << max_dif / 2 + 1 << '\n';
    }
    return 0;
}
