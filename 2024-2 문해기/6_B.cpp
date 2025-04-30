#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 987654321
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;

ll dp[10000005];

int main() {
    FIO;
    ll tc; cin >> tc;
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for(ll i=4;i<=10000000;i++) dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    while(tc--){
        ll n; cin >> n;
        cout << dp[n] % MOD << "\n";
    }
}

/*
3
5
14
87
*/