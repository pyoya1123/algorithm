#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 987654321
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;

int main() {
    FIO;

    vector<ll> fac(50005);
    fac[0] = 1;
    for(ll i=1;i<=50000;i++){
        fac[i] = (fac[i-1] * i) % MOD;
    }

    ll tc; cin >> tc;
    while(tc--){
        ll n,m; cin >> n >> m;
        vector<ll> vec(n);
        vector<ll> dp(n+2);
        vector<ll> freq(n);
        for(ll i=0;i<n;i++) cin >> vec[i];
        for(ll i=0;i<m;i++){
            ll l,r; cin >> l >> r;
            dp[l-1]++,dp[r]--;
        }
        ll cur = 0;
        for(ll i=0;i<n;i++) {
            cur += dp[i];
            freq[i] += cur;
        }
        sort(vec.begin(), vec.end());
        sort(freq.begin(), freq.end());
        ll sum = 0;
        for(ll i=0;i<n;i++) sum += vec[i] * freq[i];

        vector<ll> cnt2(m+1);
        for(auto e:freq) cnt2[e]++;
        
        ll cnt = 1;
        for(auto e:cnt2) cnt = (cnt * fac[e]) % MOD;
        cout << sum << " " << cnt << "\n";
    }
}

/*
1
3 2
10 100 1000
1 2
2 2

1
2 1
20 22
1 2

1
6 1
1 2 3 100 200 300
1 2
*/