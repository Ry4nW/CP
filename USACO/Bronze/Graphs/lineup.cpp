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

const vector<string> COWS = []() {
	vector<string> tmp{"Bessie", "Buttercup", "Belinda", "Beatrice",
	                   "Bella",  "Blue",      "Betsy",   "Sue"};
	// sort names lexicographically
	std::sort(std::begin(tmp), std::end(tmp));
	return tmp;
}();

int main() {
    // setIO("lineup");
    int N; cin >> N;
    map<string, vector<string>> neighbors;
    for (string cow : COWS) neighbors[cow] = vector<string>{};

    for (int i = 0; i < N; ++i) {
        string a;
        string b;
        string trash;
        cin >> a >> trash >> trash >> trash >> trash >> b;
        neighbors[a].push_back(b);
    }

    vector<int> order;
    vector<bool> added(COWS.size());
    for (int c = 0; i < COWS.size(); ++c) {
        if (!added[c] && neighbors[c].size())
    } return 0;
}
