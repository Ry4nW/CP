#include <bits/stdc++.h>

using namespace std;

vector<long long> prime_factors(long long n) {
    vector<long long> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        long long cur = n / 2;
        if (cur <= 6) factors.push_back(cur);
        n /= 2;
    }

    for (long long i = 3; i < (long long)(sqrt(n)) + 1; i += 2) {
        while (n % i == 0) {
            factors.push_back(n / i);
            if (i <= 6) factors.push_back(i);
            n /= i;
        }
    }

    return factors;
}

int main() {
    long long t;
    cin >> t;
    for (long long i = 0; i < t; ++i) {
        long long n;
        long long k;
        cin >> n >> k;
        if (n == 0 || k == 0) continue;
        vector<long long> test_factors = prime_factors(k);
        vector<long long> factors;
        bool used = false;
        for (long long i = 1; i < test_factors.size(); ++i) {
            long long cur = test_factors[i] * test_factors[i - 1];
            if (cur <= 6 && !used) {
                factors.push_back(cur);
                used = true;
            } else {
                used = false;
                factors.push_back(test_factors[i]);
                if (i == 1) factors.push_back(test_factors[0]);
            }
        }

        sort(factors.begin(), factors.end());
        long long temp = 1;
        vector<long long> sum;
        bool not_possible = false;
        for (long long i = factors.size() - 1; i >= 0; --i) {
            long long cur = factors[i];
            vector<long long> prime_check = prime_factors(cur);
            if (prime_check.size() == 0 && cur > 6) {
                not_possible = true;
                break;
            }
            if (temp == k || temp * cur > k || cur > 6) {
                continue;
            };
            temp *= cur;
            sum.push_back(cur);
        }
        if (not_possible) {
            cout << -1 << '\n';
            continue;
        }

        long long sum_of_els = 0;
        for (long long i = 0; i < sum.size(); ++i) {
            sum_of_els += sum[i];
        }
        sum_of_els += 1 * (n - sum.size());
        cout << sum_of_els << '\n';
    }
    return 0;
}
