// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <limits>
#include <cmath>

using namespace std;

int main() {
    int n; cin >> n;
    int p = 2 * n;
    vector<int> people(p);
    for (int i = 0; i < p; ++i) cin >> people[i];
    sort(people.begin(), people.end());

    vector<int> difs1, difs2;

    for (int i = 0, j = 1; i < n; ++i, j += 2) {
        if (j == p - 1) difs1.push_back(people[p - 1] - people[0]);
        else difs1.push_back(people[j + 1] - people[j]);
    }
    sort(difs1.begin(), difs1.end());

    for (int i = 0, j = 0; i < n; ++i, j += 2) {
        difs2.push_back(people[j + 1] - people[j]);
    }
    sort(difs2.begin(), difs2.end());

    vector<int> all_dif;
    for (int i = 0; i < n; ++i) {
        all_dif.push_back(difs1[i]); all_dif.push_back(difs2[i]);
    }
    sort(all_dif.begin(), all_dif.end());
    
    int total = 0;
    for (int i = 0; i < n - 1; ++i) {
        total += all_dif[i];
    }
    cout << total << '\n';

    // int total1 = 0; int total2 = 0;
    // for (int i = 0; i < n - 1; ++i) {
    //     total1 += difs1[i]; total2 += difs2[i];
    // }
    // cout << total1 << ' ' << total2 << '\n';
    // cout << min(total1, total2) << '\n';

    // 6 361 407 610 750 778

    // int min_dif = numeric_limits<int>::max();
    // int cur1, cur2 = 0;

    // for (int i = 0; i < n - 1; ++i) {

    //     for (int j = 0; j < p; ++j) {
    //         if (!binary_search(used.begin(), used.end(), j)) {
    //             int cur = people[j];
    //             for (int k = 0; k < p; ++k) {
    //                 if (!binary_search(used.begin(), used.end(), k) && k != j) {
    //                     int dif = abs(cur - people[k]);
    //                     if (dif < min_dif) {
    //                         min_dif = dif; 
    //                         cur1 = j; cur2 = k;
    //                     }
    //                 }
    //             }
    //         }
    //     }

    //     total_dif += min_dif;
    //     used.push_back(cur1); used.push_back(cur2);
    // }    

    // vector<tuple<int, int, int>> diff;
    // for (int i = 1; i < p; ++i) {
    //     diff.push_back({people[i] - people[i - 1], people[i], people[i - 1]});
    // }
    // sort(diff.begin(), diff.end());

    // for (tuple<int, int, int> tup : diff) {
    //     cout << get<0>(tup) << ' ' << get<1>(tup) << ' ' << get<0>(tup) << '\n';
    // }

    // int total_diff = 0;
    // vector<int> used;
    // for (int i = 0; i < n - 1; ++i) {
    //     int cur_1 = get<1>(diff[i]);
    //     int cur_2 = get<2>(diff[i]);
    //     bool avail = true;

    //     for (int person : used) {
    //         if (person == cur_1 || person == cur_2) {
    //             avail = false; 
    //             break;
    //         }
    //     }

    //     if (!avail) continue;

    //     used.push_back(cur_1); used.push_back(cur_2);
    //     total_diff += get<0>(diff[i]);
    // }
    
    // cout << total_diff << '\n';


    
    return 0;
}

