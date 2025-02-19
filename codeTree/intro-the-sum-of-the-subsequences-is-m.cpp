#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int A[100];
int dp[10005];

int main() {
    fill(&dp[0], &dp[0] + 10005, INT_MAX-5);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    dp[0] = 0;

    // Write your code here!
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=m;j>=A[i];j--){
            dp[j] = min(dp[j], dp[j-A[i]] + 1);
        }
    }

    cout << (dp[m] == INT_MAX-5 ? -1 : dp[m]);

    return 0;
}
