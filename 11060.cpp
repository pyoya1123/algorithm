#include <iostream>
using namespace std;
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

int N;
vector<int> vec;
int dp[1005];

int main()
{
    cin >> N;
    vec.resize(N + 1);
    for (int i = 0; i < N; i++)
        cin >> vec[i];

    fill(&dp[0], &dp[0] + 1005, 100000);

    dp[0] = 0;

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i <= j + vec[j])
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    if (dp[N - 1] == 100000)
        cout << -1 << "\n";
    else
        cout << dp[N - 1] << "\n";
}