#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 987654321

int dp[300005];

int N, M, K, X;
vector<int> graph[300005];

int main()
{
    fill(&dp[0], &dp[0] + 300005, MAX);
    cin >> N >> M >> K >> X;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    dp[X] = 0;
    queue<pair<int, int>> q;
    q.push({X, 0});
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        for (int i = 0; i < graph[t.first].size(); i++)
        {
            int e = graph[t.first][i];
            if (dp[e] <= t.second + 1)
                continue;
            dp[e] = t.second + 1;
            q.push({e, t.second + 1});
        }
    }

    vector<int> ans;

    for (int i = 1; i <= N; i++)
    {
        if (dp[i] == K)
            ans.push_back(i);
    }
    if (ans.size() <= 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        sort(ans.begin(), ans.end());
        for (auto e : ans)
            cout << e << "\n";
    }
}