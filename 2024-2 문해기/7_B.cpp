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

ll dp[505][505];
ll N, M;

int main() {
    FIO;
    ll tc; cin >> tc;
    while(tc--){
        memset(dp, 0, sizeof(dp));
        cin >> N >> M;
        vector<vector<ll>> m(N+1, vector<ll>(M+1));
        ll cnt = 0;
        for(ll y=1;y<=N;y++) {for(ll x=1;x<=M;x++) {cin >> m[y][x]; if(m[y][x] == 1) cnt++;}}
        for(ll x=1;x<=M;x++) dp[1][x] = dp[1][x-1] + m[1][x];
        for(ll y=1;y<=N;y++) dp[y][1] = dp[y-1][1] + m[y][1];
        for(ll y=2;y<=N;y++) for(ll x=2;x<=M;x++) dp[y][x] = max(dp[y-1][x], dp[y][x-1]) + m[y][x];
        cout << cnt - dp[N][M] << "\n";
    }
}

/*
3
5 6
0 0 0 1 0 0
0 1 0 1 0 1
1 0 0 1 0 1
0 0 1 0 1 1
0 1 0 0 0 0
2 2
1 1
1 0
4 4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
*/