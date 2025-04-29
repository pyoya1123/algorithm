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


int main() {
    FIO;
    ll tc; cin >> tc;
    while(tc--){
        ll N,M; cin >> N >> M;
        vector<ll> c(N), s(M);
        for(ll i=0;i<N;i++) cin >> c[i];
        for(ll i=0;i<M;i++) cin >> s[i];
        vector<vector<char>> teams(M);
        for(ll i=0;i<M;i++){
            ll n; cin >> n;
            ll _min = MAX;
            for(ll j=0;j<n;j++) {
                char input; cin >> input;
                _min = min(_min, c[input - 'A']);
            }
            cout << _min * s[i]<< " ";
        }
        cout << "\n";
    }
}