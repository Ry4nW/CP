#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.ignore(1, ',');
    int N; cin >> N;

    vector<int> x;
    vector<int> y;
    char eater;

    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> eater >> b;
        x.push_back(a); y.push_back(b);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    cout << x[0] - 1 << ',' << y[0] - 1 << endl;
    cout << x[x.size() - 1] + 1 << ',' << y[y.size() - 1] + 1 << endl;

    return 0;
}