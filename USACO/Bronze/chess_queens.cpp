#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

constexpr int N = 8;
vector<vector<char>> board(N, vector<char>(8, '.'));

int main() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    // since queens can be easily placed on different rows and columns,
    // generate all permutation for queens on rows, 8!
    // then check for diagonal interference

    vector<vector<int>> row_perms;
    vector<int> cur(N);
    for (int i = 0; i < N; ++i) cur[i] = i;

    do {
        row_perms.push_back(cur);
    } while (next_permutation(cur.begin(), cur.end()));

    // checking every permutation

    int perm_count{0};

    for (vector<int> perm : row_perms) {
        // check if is on unfree square
        bool skip = false;
        for (int i = 0; i < N; ++i) {
            if (board[i][perm[i]] == '*') {
                skip = true;
                break;
            }
        }
        if (skip) continue;

        // sum : if queen is seen on diag
        map<int, bool> forward_diags;   // 0 -> 14
        map<int, bool> backward_diags;  // 7 -> (-7)
        for (int i = 0; i <= 14; ++i) forward_diags[i] = false;
        for (int i = 7; i >= -7; --i) backward_diags[i] = false;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (perm[j] == i) {
                    if (forward_diags[i + j] || backward_diags[j - i]) {
                        skip = true;
                        break;
                    }
                    forward_diags[i + j] = true;
                    backward_diags[j - i] = true;
                }
            }
        }

        if (!skip) perm_count += 1;
    }

    cout << perm_count << '\n';
    return 0;
}
