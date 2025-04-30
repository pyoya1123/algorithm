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

int main() {
    FIO;

    ll tc; cin >> tc;
    while(tc--) {
        ll n; cin >> n;
        vector<ll> w(n+1);
        for(ll i=1;i<=n;i++) cin >> w[i];
        vector<vector<ll>> graph(n+1, vector<ll>(n+1));
        for(ll y=1;y<=n;y++) for(ll x=1;x<=n;x++) cin >> graph[y][x];
        
    }
}