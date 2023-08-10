#include <climits>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ifstream read("cbarn.in");
    int n{};
    read >> n;

    int min_distance = INT_MAX;
    vector<int> rooms(n);
    for (int i = 0; i < n; ++i) read >> rooms[i];

    for (int i = 0; i < n; ++i) {
        int cur_distance = 0;
        for (int j = i; j < i + n; ++j) {
            int tempj = j;
            if (j > n - 1) tempj = j % n;
            cur_distance += (j - i) * rooms[tempj];
        }
        min_distance = min(min_distance, cur_distance);
    }

    std::ofstream written("cbarn.out");
    written << min_distance << '\n';
    return 0;
}
