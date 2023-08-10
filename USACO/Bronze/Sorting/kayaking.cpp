#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int p = n * 2;
    vector<int> people(p);
    for (int& p : people) cin >> p;
    sort(people.begin(), people.end());

    int min_ins = INT32_MAX;
    for (int i = 0; i < p; ++i) {
        for (int j = i + 1; j < p; ++j) {

            vector<int> new_people;
            for (int k = 0; k < p; ++k) {
                if (k != i && k != j) {
                    new_people.push_back(people[k]);
                }
            }

            int cur_ins = 0;
            for (int l = 0; l < p - 2; l += 2) {
                cur_ins += new_people[l + 1] - new_people[l];
            }
            min_ins = min(min_ins, cur_ins);
        }

    }

    cout << min_ins << endl;

    return 0;
}
