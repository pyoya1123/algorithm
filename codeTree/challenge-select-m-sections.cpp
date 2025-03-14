#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
#define MIN INT_MIN + 5000005

int N, M;
int numbers[505];
int dp[505][255]; // dp[i][j] -> i번째 인덱스까지, m개의 구간을 가졌을 때 최대값

bool isPrint = 0;

int main() {
    fill(&dp[0][0], &dp[0][0] + 505 * 255, MIN);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> numbers[i];
    }
    for(int i=0;i<=N;i++) dp[i][0] = 0;

    dp[1][1] = numbers[1];

    for(int m=1;m<=M;m++){
        for(int l=1;l<=N;l++) {
            int sum = 0;
            for(int i=1;i<=l;i++) sum += numbers[i];

            if(m == 1) dp[l][m] = max(dp[l][m], sum);
            
            int p = l+1;
            while(p <= N) {
                
                sum -= numbers[p-l];
                sum += numbers[p];
                
                if(m == 1 || (p-l-1 >= 0 && dp[p-l-1][m-1] != MIN)) {
                    dp[p][m] = max(dp[p][m], max(sum + dp[p-l-1][m-1], dp[p-1][m]));
                }

                p++;
            }
        }
    }

    int ans = MIN;
    for(int i=1;i<=N;i++) ans = max(ans, dp[i][M]);
    cout << ans;

    return 0;
}
