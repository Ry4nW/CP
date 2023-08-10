#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main() {
    int N; cin >> N;
    string road; cin >> road;

    map<string, int> ss_count;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            string cur_ss = road.substr(i, j - i);
            if (ss_count.count(cur_ss)) {
                ss_count[cur_ss] += 1;
            } else {
                ss_count[cur_ss] = 1;
            }
        }
    }

    int min_ss = numeric_limits<int>::max();
    int min_occur = numeric_limits<int>::max();
    for (int i = 1; i <= N; ++i) {
        string cur_ss = road.substr(0, i);
        if (ss_count.count(cur_ss)) {
            if (ss_count[cur_ss] < min_occur && cur_ss.length()) {
                min_ss = cur_ss.length();
                min_occur = ss_count[cur_ss];
            }
        }
    }

    cout << min_ss << endl;

    return 0;
}
