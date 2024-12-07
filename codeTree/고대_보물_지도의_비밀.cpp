#include <iostream>
using namespace std;

int arr[100005];
int dp[100005][11];
int ans = -10005;

int main() {

    int n,k;
    cin >> n >> k;

    for(int i=1;i<=n;i++) cin >> arr[i];

    dp[0][0] = 0;

    for(int i=0;i<=k;i++){
        int sum = 0;
        for(int j=1;j<=n;j++){ 
            if(arr[j] < 0) dp[j][i+1] = max(dp[j][i+1], dp[j-1][i] + arr[j]);
            else dp[j][i] = max(dp[j][i], dp[j-1][i] + arr[j]);
        }
    }

    for(int i=0;i<=k;i++){
        for(int j=1;j<=n;j++){
            ans = max(ans, dp[j][i]);
        }
    }

    cout << ans << "\n";

    return 0;
}


/*
    dp[i][j] -> i번째 인덱스까지, j번 음수가 나왔을 때의 최대값
    1. 만약 arr[i] 가 음수인 경우,
        음수가 한 번 더 나온 경우이므로, dp[i][j+1] 에다가, 그 전 인덱스까지의 최대값  + 새로 입력된 음수 값을 비교하여 더 큰 값을 할당함.
    2. 만약 arr[i]가 양수인 경우,
        그 전 인덱스까지의 최대값 + 새로 입력된 양수 값을 비교하여 더 큰 값을 할당함.
*/