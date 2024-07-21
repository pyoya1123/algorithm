#include <iostream>
using namespace std;
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

int N, T; // 단원 개수, 공부할 수 있는 총 시간
vector<pair<int, int>> vec;
int dp[10005][105];
int ans = 0;

int main()
{
    cin >> N >> T;
    vec.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> vec[i].first >> vec[i].second; // 예상 공부 시간, 배점
    }

    for (int i = 1; i <= N; i++)
    {
        pair<int, int> e = vec[i];
        for (int w = 1; w <= T; w++)
        {
            if (e.first <= w)
            {
                dp[w][i] = max(dp[w][i - 1], dp[w - e.first][i - 1] + e.second);
            }
            else
            {
                dp[w][i] = max(dp[w][i], dp[w][i - 1]);
            }
            if (w == T)
                ans = max(ans, dp[w][i]);
        }
    }

    cout << ans << "\n";
}