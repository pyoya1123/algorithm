#include <iostream>
#include <string.h>

using namespace std;

int n;
int first_cards[1005];
int second_cards[1005];

int dp[1005][1005]; // dp[i][j] -> 첫번째 플레이어가 i번째 카드까지, 두번째 플레이어가 j번째 카드까지 버렸을 때 얻을 수 있는 최대 점수 

int main() {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> first_cards[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> second_cards[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j] == -1) continue;
            if(first_cards[i+1] < second_cards[j+1]) dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(first_cards[i+1] > second_cards[j+1]) dp[i][j+1] = max(dp[i][j+1], dp[i][j] + second_cards[j+1]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
        }
    }
    

    int ans = 0;
    for(int i=0;i<=n;i++){
        ans = max(ans, dp[n][i]);
        ans = max(ans, dp[i][n]);
    }

    cout << ans;

    return 0;
}
