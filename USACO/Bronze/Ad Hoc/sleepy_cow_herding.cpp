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
    setIO("herding");
    vector<int> cow_pos(3);
    for (int i = 0; i < 3; i++) {
        cin >> cow_pos[i];
    }
    sort(cow_pos.begin(), cow_pos.end());

    int min_ans = 0;
    int min_dif = min(cow_pos[2] - cow_pos[1], cow_pos[1] - cow_pos[0]);
    int max_dif = max(cow_pos[2] - cow_pos[1], cow_pos[1] - cow_pos[0]);

    if (min_dif - 1 == 1) min_ans = 1;
    else if (min_dif - 1 >= 2 || max_dif - 1 >= 2) min_ans = 2;

    cout << min_ans << '\n' << max_dif - 1 << endl;

    return 0;
}
