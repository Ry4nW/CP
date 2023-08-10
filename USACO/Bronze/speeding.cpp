#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("speeding");
    vector<vector<int>> segs; vector<vector<int>> bessie_segs;
    int total_segs, total_bessie;
    cin >> total_segs >> total_bessie;

    for (int i = 0; i < total_segs; ++i) {
        vector<int> cur(2);
        cin >> cur[0] >> cur[1];
        segs.push_back(cur);
    }
    for (int i = 0; i < total_bessie; ++i) {
        vector<int> cur(2);
        cin >> cur[0] >> cur[1];
        bessie_segs.push_back(cur);
    }

    vector<int> bessie; vector<int> road;

    for (vector<int> cur : bessie_segs) {
        for (int i = 0; i < cur[0]; ++i) bessie.push_back(cur[1]);
    }
    for (vector<int> cur: segs) {
        for (int i = 0; i < cur[0]; ++i) road.push_back(cur[1]);
    }
    
    int violate = 0;
    for (int i = 0; i < 100; ++i) {
        if (bessie[i] > road[i]) {
            violate = max(violate, bessie[i] - road[i]);
        }
    }

    cout << violate << '\n';
    return 0;
}



