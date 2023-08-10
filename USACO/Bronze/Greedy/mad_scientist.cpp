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
    setIO("breedflip");
    int len; cin >> len;
    string A, B; cin >> A >> B;

    bool in_ss = false;
    int switches = 0;
    for (int i = 0; i < len; i++) {
        if (A[i] != B[i]) {
            if (!in_ss) {
                switches += 1;
                in_ss = true;
            }
        } else {
            in_ss = false;
        }
    }

    cout << switches << endl;
    return 0;
}
