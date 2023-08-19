#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a;
        int k;
        int b;
        cin >> a >> k >> b;

        int sum = a + k + b;
        bool found = false;

        int half_both = b / 2;
        int katie = k + half_both;
        int anna = a + (b - half_both);

        if (anna > katie)
            cout << "First" << '\n';
        else
            cout << "Second" << '\n';
    }
    return 0;
}
