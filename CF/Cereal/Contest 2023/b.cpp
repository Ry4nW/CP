#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        int k;
        cin >> n >> k;

        if (k % 2 != 0) {
            cout << "NO" << '\n';
            continue;
        }

        vector<bool> str(n);

        for (int j = 0; j < k - 1; ++j) str[j] = true;

        vector<char> bin_str(n);
        for (int l = 0; l < n; ++l) {
            if (str[l])
                bin_str[l] = '1';
            else
                bin_str[l] = '0';
        }

        string s(bin_str.begin(), bin_str.end());
        cout << "YES" << '\n' << s << '\n';

        // bool found = false;
        // for (int j = 0; j < n; j++) {
        //     str[j] = true;
        //     do {
        //         int difs{};
        //         for (int j = 0; j < n; ++j) {
        //             // int dif_index =
        //             if (str[j] != str[n - j - 1]) difs++;
        //         }
        //         if (difs == k) {
        //             found = true;
        //             break;
        //         }
        //     } while (next_permutation(str.begin(), str.end()));

        //     if (found) {
        //         vector<char> bin_str(n);
        //         for (int k = 0; k < n; ++k) {
        //             if (str[k])
        //                 bin_str[k] = '1';
        //             else
        //                 bin_str[k] = '0';
        //         }

        //         string s(bin_str.begin(), bin_str.end());
        //         cout << "YES" << '\n' << s << '\n';
        //         break;
        //     }
        // }
        // if (!found) cout << "NO" << '\n';
    }
}