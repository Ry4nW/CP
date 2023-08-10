#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<int> nums;
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        int cur; cin >> cur;
        nums.insert(cur);
    }

    cout << nums.size() << endl;
    return 0;
}

