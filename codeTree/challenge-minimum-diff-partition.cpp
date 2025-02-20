#include <iostream>
#include <string.h>
#include <climits>
#include <cmath>

using namespace std;

int n;
int arr[100];
int dp[1000005];

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n;

    int sum = 0;

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    for(int i=0;i<n;i++){
        for(int j=100000-arr[i];j>=0;j--){
            if(dp[j] != -1) {
                dp[j+arr[i]]++;
            }
        }
    }

    int ans = INT_MAX;
    
    for(int i=1;i<sum;i++){
        if(dp[i] != -1) {
            int tmp = sum - i;
            ans = min(ans, abs(tmp - i));
        }
    }

    cout << ans;

    return 0;
}
