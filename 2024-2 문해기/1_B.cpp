#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <numeric>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 987654321
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000009;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    FIO;
    ll tc; cin >> tc;
    while(tc--){
        ll n; cin >> n;
        vector<ll> vec(n);
        for(ll i=0;i<n;i++) cin >> vec[i];
        ll ans = vec[0];
        for(ll i=1;i<n;i++) {
            ll g = gcd(ans, vec[i]);
            ans = (ans / g) * vec[i];
        }
        cout << ans << "\n";
    }
}