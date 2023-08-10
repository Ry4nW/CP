#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());

    int cur = -1; int distinct = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] != cur) {
            distinct++; cur = nums[i];
        }
    }

    cout << distinct << '\n';
    return 0;
}
