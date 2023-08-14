#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> pandas(n);
        for (int j = 0; j < n; ++j) cin >> pandas[j];

        vector<vector<int>> distances;
        for (int j = 0; j < n; ++j) {
            vector<int> distance(n);
            for (int k = 0; k < n; ++k) cin >> distance[k];
            distances.push_back(distance);
        }

        bool found = false;
        vector<int> cur_order(n);

        for (int j = 0; j < n; ++j) {
            vector<int> cur = distances[j];

            for (int k = 0; k < n; ++k) {
                bool bad = false;

                int cur_panda = pandas[k];
                for (int l = 0; l < n; ++l) {
                    int cur_comp = pandas[l];
                    if (cur_comp == cur_panda)
                        continue;
                    else if (find(cur.begin(), cur.end(), abs(cur_comp - cur_panda)) == cur.end()) {
                        bad = true;
                        break;
                    }
                }
                if (!bad && !cur_order[k]) {
                    cur_order[k] = j + 1;
                    break;
                }
            }
        }

        for (int j : cur_order) {
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}
