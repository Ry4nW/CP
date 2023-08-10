#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool>& visited, vector<vector<int>> &graph) {
	visited[node] = true;
	for (auto neighbour : graph[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour, visited, graph);
        }
	}
}

int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m;
    vector<bool> visited(n);
    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    vector<int> paths;
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
            dfs(i, visited, graph); 
            paths.push_back(i + 1);
        }
    }

    cout << paths.size() / 2 << endl;

    for (int i = 1; i < paths.size(); ++i) { cout << paths[i] << ' ' << paths[i - 1] << endl; }

    return 0;
}
