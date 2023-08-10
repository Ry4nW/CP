// #include <bits/stdc++.h>
// using namespace std;

// void setIO() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     // if (s.size()) {
//     //     freopen((s + ".in").c_str(), "r", stdin);
//     //     freopen((s + ".out").c_str(), "w", stdout);
//     // }
// }

// int count_evens(vector<char>& cows) {
//     int count = 0;
//     for (int i = 1; i <= cows.size(); i += 2) {
//         if (cows[i] == 'G') count++;
//     }
//     return count;
// }

// int main() {
//     setIO();
//     int N{};
//     string cows{};
//     cin >> N >> cows;

//     vector<char> positions(cows.begin(), cows.end());

//     int reversals = 0;
//     int temp_count = numeric_limits<int>::max();
//     int cur_count = count_evens(positions);
//     while (temp_count > cur_count) {
//         if (reversals > 0) cur_count = temp_count;
//         temp_count = 0;
//         vector<char> max_attempt;

//         for (int i = 1; i < N; i += 2) {
//             vector<char> cur_prefix = {positions.begin(), positions.begin() + i + 1};
//             reverse(cur_prefix.begin(), cur_prefix.end());
//             vector<char> the_rest = {positions.begin() + i + 1, positions.end()};

//             cur_prefix.insert(cur_prefix.end(), the_rest.begin(), the_rest.end());

//             int cur_even_count = count_evens(cur_prefix);
//             if (cur_even_count > temp_count) {
//                 temp_count = cur_even_count;
//                 max_attempt = cur_prefix;
//             }
//         }

//         if (temp_count > cur_count) {
//             reversals++;
//             positions = max_attempt;
//         }
//     }

//     cout << reversals << '\n';
//     return 0;
// }

#include <cassert>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
    int cow_num;
    string cows;
    std::cin >> cow_num >> cows;
    assert(cows.size() == cow_num && cow_num % 2 == 0);

    int flips = 0;
    for (int c = cow_num - 2; c >= 0; c -= 2) {
        string sub = cows.substr(c, 2);
        if (sub[0] == sub[1]) {
            continue;
        }
        if ((sub == "GH" && flips % 2 == 0) || (sub == "HG" && flips % 2 == 1)) {
            flips++;
        }
    }

    cout << flips << endl;
}
