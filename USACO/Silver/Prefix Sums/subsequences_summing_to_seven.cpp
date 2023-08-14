#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("div7");
    int N;
    cin >> N;
    vector<int> cows(N);
    vector<ll> prefix(N + 1, 0);

    for (int i = 0; i < N; ++i) {
        int cur;
        cin >> cur;
        cows[i] = cur;
        if (i != 0) prefix[i + 1] = prefix[i];
        prefix[i + 1] += cur;
    }

    int max_subseq{};

    for (int i = N; i > -1; --i) {
        for (int j = i - 1; j > -1; --j) {
            if ((prefix[i] - prefix[j]) % 7 == 0) max_subseq = max(max_subseq, i - j);
        }
    }

    cout << max_subseq << '\n';
    return 0;
}
