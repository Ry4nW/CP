#include <bits/stdc++.h>

using namespace std;

int main() {
    string s{};
    cin >> s;

    vector<char> permutation;
    for (int i = 0; i < s.size(); ++i) {
        permutation.push_back(s[i]);
    }
    sort(permutation.begin(), permutation.end());

    vector<string> all_perms;

    do {
        string current = "";
        for (int i = 0; i < s.size(); ++i) {
            current += permutation[i];
        }
        all_perms.push_back(current);
    } while (next_permutation(permutation.begin(), permutation.end()));

    cout << all_perms.size() << '\n';
    for (int i = 0; i < all_perms.size(); ++i) cout << all_perms[i] << '\n';

    return 0;
}
