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
    setIO("notlast");
    unordered_map<string, int> cows;
    string names[] { "Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta" };

    for (string& cow : names) {
        cows[cow] = 0;
    }

    int amt; cin >> amt;
    for (int i = 0; i < amt; ++i) {
        string cur_name; int cur_amt;
        cin >> cur_name >> cur_amt;
        cows[cur_name] += cur_amt;
    }

    map<int, vector<string>> milk_counts;
    set<int> milk_amts;

    for (pair<string, int> cow : cows) {
        milk_counts[cow.second].push_back(cow.first);
        milk_amts.insert(cow.second);
    }

    vector<int> milk_amts_vec;
    for (int cur_amt : milk_amts) milk_amts_vec.push_back(cur_amt);    

    if (milk_amts.size() == 1 || milk_counts[milk_amts_vec[1]].size() > 1) {
        cout << "Tie" << endl;
    } else {
        cout << milk_counts[milk_amts_vec[1]][0] << endl;
    }

    return 0;
}
