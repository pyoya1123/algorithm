#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    // Total sum of n over all test cases does not exceed 2e5
    while (t--) {
        int n;
        cin >> n;
        vector<int> degree(n + 1, 0);
        vector<pair<int, int>> edges;
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            degree[u]++;
            degree[v]++;
            edges.push_back({u, v});
        }
        int max_deg = 0;
        for (int i = 1; i <= n; ++i) {
            max_deg = max(max_deg, degree[i]);
        }
        int max_val = 0;
        for (auto edge : edges) {
            int u = edge.first, v = edge.second;
            int val = (degree[u] - 1) + (degree[v] - 1);
            max_val = max(max_val, val);
        }
        int ans = max(max_deg, max_val);
        if (ans == 0) ans = 1;
        cout << ans << endl;
    }
    return 0;
}
