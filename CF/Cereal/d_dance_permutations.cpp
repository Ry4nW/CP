#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dance(n);
    for (int i = 1; i <= n; ++i) dance[i - 1] = i;
    int first_one_count{};
    int a = tgamma(n);
    vector<int> prev = dance;
    int prev_i = 0;
    // vector<vector<int>> perms;
    int distance{};
    do {
        first_one_count++;
        if (first_one_count <= a) continue;
        if (dance[0] == 1) first_one_count++;
        for (int i : dance) {
            cout << i << ' ';
        }
        cout << '\n';
        for (int i = 0; i < n; ++i) {
            if (dance[i] == 1) {
                distance += abs(i - prev_i);
                prev_i = i;
            }
        }

        prev = dance;
    } while (next_permutation(dance.begin(), dance.end()));

    cout << distance << '\n';
    cout << "first one " << first_one_count << '\n';
    return 0;
}
// for (vector<int> vec : perms) {

// }

// for (int i = 0; i < n; ++i) {
//     if (dance[i] != prev[i]) {
//         if (prev[i] < dance[i]) {
//             perms.push_back(dance);
//         };
//         break;
//     }
// }