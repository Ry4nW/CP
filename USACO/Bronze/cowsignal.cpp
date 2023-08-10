#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("cowsignal");
    int M, N, K;
    cin >> M >> N >> K;
    string message;
    
    for (int i = 0; i < M; ++i) {
        string cur_str;
        for (int j = 0; j < N; ++j) {
            char cur; cin >> cur;
            for (int k = 0; k < K; ++k) {
                cur_str += cur;
            }
        }
        for (int k = 0; k < K; ++k) {
            message += cur_str; message += '\n';
        }
    }

    cout << message;
    return 0;
}
