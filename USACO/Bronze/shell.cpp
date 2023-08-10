#include <bits/stdc++.h>
using namespace std;

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, const char **argv)
{
    setIO("shell");
    int guesses;
    cin >> guesses;

    vector<int> possible_points = {0, 0, 0};
    vector<vector<int>> guess_input;

    for (int i = 0; i < guesses; ++i)
    {
        int a, b, g;
        cin >> a >> b >> g;
        guess_input.push_back({a, b, g});
    }

    for (int i = 0; i < 3; ++i)
    {
        int table[3]{1, 2, 3};
        int pos = i + 1;
        for (int j = 0; j < guesses; ++j)
        {
            vector<int> cur = guess_input[j];
            int a = cur[0] - 1;
            int b = cur[1] - 1;
            int g = cur[2] - 1;

            int temp = table[a];
            table[a] = table[b];
            table[b] = temp;

            if (table[g] == pos) possible_points[i]++;
        }
    }

    int max = *max_element(possible_points.begin(), possible_points.end());
    cout << max << endl;

    return 0;
}
