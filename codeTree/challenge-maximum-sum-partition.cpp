#include <iostream>
#include <string.h>
#include <climits>
#include <cmath>

using namespace std;

int n;
int arr[105];
const int OFFSET = 100000;
int dp[105][100005 + OFFSET];
int sum = 0;

void update(int i, int j, int prev_i, int prev_j, int val) {
    if(prev_j < -sum || prev_j > sum || dp[prev_i][prev_j + OFFSET] == INT_MIN) return;
    dp[i][j + OFFSET] = max(dp[i][j + OFFSET], dp[prev_i][prev_j + OFFSET] + val);
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    
    for(int i=0;i<=n;i++){
        for(int j=-sum;j<=sum;j++){
            dp[i][j+OFFSET] = INT_MIN;
        }
    }
    dp[0][0+OFFSET] = 0;

    for(int i=1;i<=n;i++){
        for(int j=-sum;j<=sum;j++){
            update(i,j,i-1,j+arr[i], 0);
            update(i,j,i-1,j-arr[i],arr[i]);
            update(i,j,i-1,j,0);
        }
    }

    cout << dp[n][0+OFFSET];

    return 0;
}
