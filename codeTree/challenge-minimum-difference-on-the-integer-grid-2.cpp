#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 987654321

int n;
int grid[105][105];
int dp[105][105];

void initDP(){
    fill(&dp[0][0], &dp[0][0] + 105 * 105, MAX);

    dp[1][1] = grid[1][1];

    for(int y=2;y<=n;y++) dp[y][1] = max(dp[y-1][1], grid[y][1]);
    for(int x=2;x<=n;x++) dp[1][x] = max(dp[1][x-1], grid[1][x]);
}

int solve(int lower_bound) {
    for(int y=1;y<=n;y++) for(int x=1;x<=n;x++) if(grid[y][x] < lower_bound) grid[y][x] = MAX;

    initDP();

    for(int y=2;y<=n;y++) for(int x=2;x<=n;x++) dp[y][x] = max(min(dp[y-1][x], dp[y][x-1]), grid[y][x]);

    return dp[n][n];
}


int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = MAX;

    for(int lower_bound=1;lower_bound<=100;lower_bound++) {
        int upper_bound = solve(lower_bound);

        if(upper_bound == MAX) continue;

        ans = min(ans, upper_bound - lower_bound);
    }

    cout << ans << "\n";

    return 0;
}
