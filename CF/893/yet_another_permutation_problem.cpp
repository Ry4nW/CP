#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (max(a, b) % min(a, b) == 0) return min(a, b);

    int max_div = 1;
    for (int i = 2; i < min(a, b) / 2 + 1; ++i) {
        if (a % i == 0 && b % i == 0) max_div = max(max_div, i);
    }
    return max_div;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> nums(n);

        for (int j = 1; j <= n; ++j) nums[j - 1] = j;

        int m{};
        vector<int> max_perm;
        do {
            unordered_set<int> cur;
            for (int j = 0; j < n; ++j) {
                cur.insert(gcd(nums[j], nums[j % n + 1]));
            }
            int siz = cur.size();
            if (siz > m) {
                max_perm.clear();
                max_perm.insert(max_perm.end(), cur.begin(), cur.end());
                m = siz;
            }
        } while (next_permutation(nums.begin(), nums.end()));

        for (int e : max_perm) cout << e << ' ';
        cout << '\n';
    }
    return 0;
}
