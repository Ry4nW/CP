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
    setIO("outofplace");
    int N{};
    cin >> N;

    vector<int> org_line(N);
    vector<int> sorted_line(N);
    for (int i = 0; i < N; ++i) {
        int cur{};
        cin >> cur;
        org_line[i] = cur;
        sorted_line[i] = cur;
    }

    sort(sorted_line.begin(), sorted_line.end());

    int bessie{};
    int pos{};
    bool found_pos = false;
    int org_pos{};
    for (int i = 0; i < N; ++i) {
        int cur = sorted_line[i];
        if (cur != org_line[i]) {
            if (!found_pos) {
                bessie = cur;
                pos = i;
                found_pos = true;
            } else if (org_line[i] == bessie) {
                org_pos = i;
                break;
            }
        }
    }

    if ((pos == 0 && bessie < org_line[pos + 1]) ||
        (pos == org_line.size() && bessie > org_line[pos - 1]) ||
        (org_line.size() >= 3 && bessie > org_line[org_pos - 1] &&
         bessie < org_line[org_pos + 1])) {
        cout << 0 << '\n';
        return 0;
    }

    int i = org_pos;
    unordered_set<int> nums;
    bool isLeft = org_pos - pos > 0;
    // bessie will be either swapped towards the left or right
    if (isLeft)
        i--;
    else
        i++;

    while (pos != i) {
        nums.insert(org_line[i]);
        if (isLeft)
            i--;
        else
            i++;
    }
    nums.insert(org_line[i]);
    cout << nums.size() << '\n';

    return 0;
}
