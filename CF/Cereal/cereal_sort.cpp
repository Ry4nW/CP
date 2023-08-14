#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    map<int, int> line;  // id, amount

    for (int i = 0; i < N; ++i) {
        int cur;
        cin >> cur;
        line[cur]++;
    }

    int line_amt = N;
    long long time = 0;
    for (auto i : line) {
        time += line_amt;
        line_amt -= i.second;
    }

    cout << time << '\n';
    return 0;
}
