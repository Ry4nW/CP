#include <bits/stdc++.h>

using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    double cur = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
    return cur;
}

// currently searching through whole square space of the radius of scanner, too slow
int main() {
    int H;
    int K;
    int n;
    cin >> H >> K >> n;
    vector<pair<int, int>> monitors;
    for (int i = 0; i < n; ++i) {
        pair<int, int> cur;
        cin >> cur.first >> cur.second;
        monitors.push_back(cur);
    }

    double max_rad{};
    for (int i = 1; i < H; ++i) {
        for (int j = 1; j < K; ++j) {
            pair<int, int> current_coordinate = {j, i};
            if (find(monitors.begin(), monitors.end(), current_coordinate) != monitors.end())
                continue;

            vector<int> border_lims{i, abs(H - j), abs(K - i), j};
            double max_to_border = abs(*min_element(border_lims.begin(), border_lims.end()));
            double cur_max = max_to_border;

            // check monitors
            // x1 y1 j i
            // x2 y2 first second
            for (pair<int, int> monitor : monitors) {
                double cur_distance = distance(j, i, monitor.first, monitor.second);
                if (cur_distance < cur_max) cur_max = cur_distance;
            }

            max_rad = max(max_rad, cur_max);
        }
    }

    cout << fixed;
    cout << setprecision(7);
    cout << max_rad << '\n';
    return 0;
}
