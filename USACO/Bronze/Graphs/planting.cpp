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
    setIO("planting");
    int N; cin >> N;
    vector<int> adj[N];

    for (int i = 0; i < N - 1; ++i) {
        int a, b; cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    vector<int> colors(N);
    for (int i = 0; i < N; ++i) colors[i] = -1;

    int min_colors = 2;
    for (int i = 0; i < N - 1; ++i) {
        int found = -1;
        int cur_color = 2;
        for (int j = 0; j < adj[i].size(); ++j) {
            int neighbor = adj[i][j];
            if (neighbor != -1 && neighbor != found) {
                if (found != -1) cur_color++;
                else found = neighbor;
            } else if (neighbor != found) {
                cur_color++;
            }
        }
        min_colors = max(min_colors, cur_color);
    }

    cout << min_colors << endl;
    return 0;
}
