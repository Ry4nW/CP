#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("milkorder");
    int N{}, M{}, K{};
    cin >> N >> M >> K;

    vector<int> hierarchy(M);
    for (int i = 0; i < M; ++i) cin >> hierarchy[i];

    vector<int> order(N, 0);

    for (int i = 0; i < K; ++i) {
        int a{}, b{};
        cin >> a >> b;  // cow, pos
        order[b - 1] = a;
    }

    int prev = 0;
    for (int i = 0; i < order.size(); ++i) {
        if (order[i]) continue;
        order[i] = 1;

        bool found = true;
        int j = 0;  // cur hierarchy cow
        int k = 0;  // cur search pos on order
        int cur = hierarchy[0];
        while (j < hierarchy.size() && k < order.size()) {
            if (find(order.begin(), order.end(), cur) != order.end()) {
                while (order[k] != cur && k < order.size()) k += 1;
                j += 1;
                cur = hierarchy[j];
            } else if (!order[k]) {
                j += 1;
                cur = hierarchy[j];
            } else if (j < hierarchy.size() - 1 && order[k] == hierarchy[j + 1]) {
                found = false;
                break;
            }
            k += 1;
        }

        if (j < hierarchy.size()) found = false;

        if (found) {
            cout << i + 1 << '\n';
            break;
        }

        order[i] = 0;
    }
    return 0;
}
