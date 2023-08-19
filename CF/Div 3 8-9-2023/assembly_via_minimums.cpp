#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<int, int> num_occurs;
        int amt = (n * (n - 1)) / 2;
        vector<int> nums(amt);

        for (int i = 0; i < amt; ++i) {
            int cur;
            cin >> cur;
            num_occurs[cur]++;
            nums[i] = cur;
        }

        sort(nums.begin(), nums.end());
        set<int> nums_set(nums.begin(), nums.end());
        vector<int> distinct_nums(nums_set.begin(), nums_set.end());
        int l = distinct_nums.size();
        int s = nums.size();

        vector<int> out(n);
        int cur_i = 0;
        int i = 0;
        while (i < n) {
            int cur_num = distinct_nums[cur_i];
            out[i] = cur_num;
            int spaces_left = (n - i - 1);
            num_occurs[cur_num] -= min(spaces_left, num_occurs[cur_num]);
            if (num_occurs[cur_num] <= 0 && cur_i < l - 1) cur_i++;

            i++;
        }

        for (int a : out) cout << a << ' ';
        cout << '\n' << '\n';
    }

    return 0;
}
