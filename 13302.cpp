#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 987654321
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000009;

bool v[105]; // if true, cant go resort
ll dp[205][66];
ll ans = MAX;
ll N,M; 

int main() {
    FIO;
 
    cin >> N >> M;
    for(ll i=0;i<M;i++) {
        ll input; cin >> input; v[input] = true;
    }

    fill(&dp[0][0], &dp[0][0] + 205 * 66, MAX);

    dp[0][0] = 0;
    for(ll n=1;n<=N;n++){
        for(ll s=0;s<=60;s++){
            if(v[n]) dp[n][s] = min(dp[n][s], dp[n-1][s]);
            dp[n][s] = min(dp[n][s], dp[n-1][s] + 10000);
            if(n >= 3 && s >= 1) dp[n][s] = min(dp[n][s], dp[n-3][s-1] + 25000);
            if(n >= 5 && s >= 2) dp[n][s] = min(dp[n][s], dp[n-5][s-2] + 37000);
            if(s >= 3) dp[n][s-3] = min(dp[n][s-3], dp[n-1][s]);
        }
    }

    for(ll n=1;n<=N;n++){
        for(ll s=0;s<=60;s++){
            if(n + (s/3) >= N) ans = min(ans, dp[n][s]);
        }
    }

    cout << ans;
}


/*
23 5
7 13 19 20 22
*/