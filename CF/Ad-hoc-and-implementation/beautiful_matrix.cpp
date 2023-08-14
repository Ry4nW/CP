#include <bits/stdc++.h>

using namespace std;

int main() {
    int a{};
    int b{};
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int cur;
            cin >> cur;
            if (cur) {
                a = i;
                b = j;
            }
        }
    }

    cout << abs(2 - a) + abs(2 - b) << '\n';
    return 0;
}
