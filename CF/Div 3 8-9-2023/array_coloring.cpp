#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int a;
        cin >> a;
        vector<int> colors(a);
        for (int j = 0; j < a; ++j) cin >> colors[j];

        bool found = false;

        // slow since brute forcing through every permutation, like 50!/5 at max

        // // for every 1, 2, ... a array of numbers,
        // // go through 1, 2, ... a - 1 number of colors
        // // e.g. a = 8, so [1, 7], [2, 6], [3, 5]...
        // bool found = false;

        // for (int i = 1; i < a; ++i) {
        //     int n[a];
        //     for (int j = 0; j < i; ++j) n[j] = 0;
        //     for (int j = i; j < a; ++j) n[j] = 1;

        //     do {
        //         int sum1{};
        //         int sum2{};
        //         for (int j = 0; j < a; j++) {
        //             if (n[j])
        //                 sum1 += colors[j];
        //             else
        //                 sum2 += colors[j];
        //         }
        //         if ((sum1 % 2 == 0 && sum2 % 2 == 0) || (sum1 % 2 != 0 && sum2 % 2 != 0))
        //             found = true;
        //     } while (next_permutation(n, n + a) && !found);

        //     if (found) break;
        // }

        // since odd + odd = even, even + even = even
        // and even + odd  = odd,
        // iterate through each potential combo for both oddodd and eveneven

        vector<int> sum1_indices;
        vector<int> sum1a_indices;
        int sum1{};
        int sum1a{};

        for (int i = 0; i < a; ++i) {
            if (colors[i] % 2 == 0) {
                sum1_indices.push_back(i);
                sum1 += colors[i];
            } else {
                sum1a_indices.push_back(i);
                sum1a += colors[i];
            }

            // eveneven
            if (sum1_indices.size() > 1) {
                int sum2{};
                for (int j = 0; j < a; ++j) {
                    if (find(sum1_indices.begin(), sum1_indices.end(), j) != sum1_indices.end())
                        sum2 += colors[j];
                }
                if ((sum1 % 2 == 0 && sum2 % 2 == 0) || (sum1 % 2 != 0 && sum2 % 2 != 0)) {
                    found = true;
                    break;
                }
            }

            // oddodd
            if (sum1a_indices.size() > 1) {
                int sum2{};
                for (int j = 0; j < a; ++j) {
                    if (find(sum1a_indices.begin(), sum1a_indices.end(), j) != sum1a_indices.end())
                        sum2 += colors[j];
                }
                if ((sum1a % 2 == 0 && sum2 % 2 == 0) || (sum1a % 2 != 0 && sum2 % 2 != 0)) {
                    found = true;
                    break;
                }
            }
        }

        // oddodd

        if (found)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}
