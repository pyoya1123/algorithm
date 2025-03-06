#include <iostream>

using namespace std;
typedef long long ll;

int n;

ll const MOD = 1000000007;

ll dp[1005][4][2][4]; // dp[i][j][e][w] -> [i번째 인덱스까지], [j:0 -> G, j:1 -> B, j:2 -> T], 바로 전 인덱스에 B를 삽입했으면 1, [i번째 인덱스까지 삽입된 T의 개수]

int main() {
    cin >> n;

    dp[1][0][0][0] = dp[1][1][0][0] = dp[1][2][0][1] = 1;

    for(int i=2;i<=n;i++) {
        // G
        for(int t=0;t<=2;t++){
            // 그 전 인덱스에서 B를 삽입하지 않았을 때 
            dp[i][0][0][t] += (dp[i-1][0][0][t] + dp[i-1][0][1][t]) % MOD;
            if(t != 0) dp[i][0][0][t] += (dp[i-1][2][0][t] + dp[i-1][2][1][t]) % MOD;

            // 그 전 인덱스에서 B를 삽입했을 때
            dp[i][0][1][t] += (dp[i-1][1][0][t] + dp[i-1][1][1][t]) % MOD;
        }

        // B
        for(int t=0;t<=2;t++){
            // 그 전 인덱스에서 B를 삽입하지 않았을 때 
            dp[i][1][0][t] += (dp[i-1][0][0][t] + dp[i-1][0][1][t]) % MOD;
            if(t != 0) dp[i][1][0][t] += (dp[i-1][2][0][t] + dp[i-1][2][1][t]) % MOD;

            // 그 전 인덱스에서 B를 삽입했을 때
            dp[i][1][1][t] += (dp[i-1][1][0][t]) % MOD;
        }

        // T
        for(int t=1;t<=2;t++){
            // 그 전 인덱스에서 B를 삽입하지 않았을 때 
            dp[i][2][0][t] += (dp[i-1][0][0][t-1] + dp[i-1][0][1][t-1] + dp[i-1][2][0][t-1] + dp[i-1][2][1][t-1]) % MOD;

            // 그 전 인덱스에서 B를 삽입했을 때
            dp[i][2][1][t] += (dp[i-1][1][0][t-1] + dp[i-1][1][1][t-1]) % MOD;
        }
    }

    ll sum = 0;
    for(int j=0;j<=2;j++)for(int b=0;b<=1;b++)for(int t=0;t<=2;t++) sum += (dp[n][j][b][t]) % MOD; // += 보다 % 가 우선순위가 더 높아서, 모드 연산 후에 += 연산이 수행되므로 마지막에 %MOD 를 더 해줘야함.
    cout << sum % MOD;
    

    return 0;
}
