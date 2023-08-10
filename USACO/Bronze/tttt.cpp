#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    vector<vector<char>> table;

    for (int i = 0; i < 3; ++i) {
        vector<char> cur;
        for (int j = 0; j < 3; ++j) {
            char cur_char; cin >> cur_char;
            cur.push_back(cur_char);
        }
        table.push_back(cur);
    }

    vector<vector<char>> seen_groups;
    int uniq_count = 0;
    int gsingle = 0; int gdouble = 0; 

    for (int i = 0; i < 3; ++i) {
        vector<char> seen;
        for (int j = 0; j < 3; ++j) {
            bool alr = false;
            for (char cur : seen) {
                if (cur == table[i][j]) {
                    alr = true;
                    break;
                }
            }
            if (!alr) {
                uniq_count++; seen.push_back(table[i][j]);
            }
        }

        bool unique = true;
        string str_seen; for (int i = 0; i < seen.size(); ++i) str_seen += seen[i];
        for (vector<char> group : seen_groups) {
            string str_group; 
            for (int i = 0; i < group.size(); ++i) str_group += group[i];
            if (str_seen == str_group) {
                unique = false; break;
            }
        }
        cout << uniq_count;
        if (unique) {
            if (uniq_count == 1) { 
                gsingle++; seen_groups.push_back(seen); 
            } else if (uniq_count == 2) { 
                gdouble++; seen_groups.push_back(seen); 
            }
        }
    }

    cout << gsingle << '\n' << gdouble << '\n';
    return 0;
}
