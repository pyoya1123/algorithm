#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 987654321
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000009;

ll parent[1005];

ll find(ll x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool merge(ll a, ll b, const vector<ll>& w) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(w[a] > w[b]) parent[a] = b;
    else parent[b] = a;
    return true;
}

struct node {
    ll a;
    ll b;
    ll cost;
};

struct cmp {
    bool operator()(const node& a, const node& b){
        return a.cost > b.cost;
    }
};

/// @brief 
/// @return 
int main() {
    FIO;
    ll tc; cin >> tc;
    while(tc--){
        ll N; cin >> N;
        for(ll i=1;i<=N;i++) parent[i] = i;
        vector<ll> w(N+1);
        for(ll i=1;i<=N;i++) cin >> w[i];
        vector<vector<ll>>graph(N+1, vector<ll>(N+1));
        for(ll y=1;y<=N;y++) for(ll x=1;x<=N;x++) cin >> graph[y][x];
        
        priority_queue<node, vector<node>, cmp> pq;
        for(ll y=1;y<=N;y++) for(ll x=y+1;x<=N;x++) pq.push({y,x,graph[y][x]});
        for(ll i=1;i<=N;i++) pq.push({0,i,w[i]});

        ll ans = 0;
        while(!pq.empty()){
            node t = pq.top(); pq.pop();
            if(merge(t.a, t.b, w)) ans += t.cost;
        }
        cout << ans << "\n";
    }
}


/*
2
4
5 4 4 3
0 2 2 2
2 0 3 3
2 3 0 4
2 3 4 0
5
2 17 6 1 35
0 8 4 7 10
8 0 15 15 22
4 15 0 1 35
7 15 1 0 2
10 22 35 2 0

ans:
9
14


1
3
10 10 1
0 2 9
2 0 2
9 2 0

ans:
5
*/