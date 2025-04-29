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
#include <stack>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 987654321
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000009;

struct cmp {
    bool operator()(const pair<ll,ll>& a, const pair<ll,ll>& b){
        return a.second > b.second;
    }
};

void bfs(ll srt, const vector<vector<pair<ll,ll>>>& graph, vector<ll>& dp) {
    dp[srt] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, cmp> pq;
    pq.push({srt,0});
    while(!pq.empty()){
        auto [te,tv] = pq.top(); pq.pop();
        for(auto [e,v] : graph[te]){
            if(dp[e] <= tv + v) continue;
            dp[e] = tv + v;
            pq.push({e, tv + v});
        }
    }
}

int main() {
    FIO;
    ll tc; cin >> tc;
    while(tc--){
        ll N,M; cin >> N >> M;
        vector<ll> dp(N+1, MAX);
        vector<ll> dp2(N+1, MAX);
        vector<vector<pair<ll,ll>>> graph(N+1, vector<pair<ll,ll>>());
        vector<vector<pair<ll,ll>>> graphR(N+1, vector<pair<ll,ll>>());
        for(ll i=0;i<M;i++){
            ll a,b,x,y; cin >> a >> b >> x >> y;
            graph[a].push_back({b,x});
            graph[b].push_back({a,y});
            graphR[a].push_back({b,y});
            graphR[b].push_back({a,x});
        }
        ll K; cin >> K;
        vector<ll> client(K);
        for(ll i=0;i<K;i++) cin >> client[i];

        bfs(1, graph, dp);
        bfs(1, graphR, dp2);
        ll ans = -1;
        for(auto e:client) ans = max(ans, dp[e] + dp2[e]);
        cout << ans << "\n";
    }
}


/*
2
5 5
5 1 3 1
1 2 2 2
1 3 3 2
2 4 3 5
3 4 6 2
3
2 4 5
7 10
3 5 15 35
6 1 14 47
3 4 1 29
5 4 22 27
4 7 13 2
3 2 50 29
1 2 9 62
5 1 16 70
7 6 42 25
4 6 8 15
3 
6 7 5

*/