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
vector<ll> graph[100005];
vector<ll> w; // 공간 i 에 Wi번 광석 존재 
vector<ll> jew_vec;
bool jew[100005];
ll ans[100005];

struct node {
    ll cur;
    ll prev;
    ll d;
};

void f() {
    queue<node> q; q.push({0,0,0});
    while(!q.empty()){
        node t = q.front(); q.pop();
        if(jew[w[t.cur]]) ans[w[t.cur]] = t.d;
        for(auto e:graph[t.cur]){
            if(e == t.prev) continue;
            q.push({e,t.cur,t.d+1});
        }
    }
}

int main() {
    FIO;
    ll tc; cin >> tc;
    while(tc--){
        ll n,k; cin >> n >> k;
        w.resize(n+1);
        for(ll i=1;i<=n;i++) cin >> w[i];
        memset(jew, false, sizeof(jew));
        jew_vec.clear();
        for(ll i=0;i<k;i++) {
            ll input; cin >> input; jew[input] = true;
            jew_vec.push_back(input);
        }
        for(ll i=0;i<=100000;i++) graph[i].clear();
        for(ll i=0;i<n;i++){
            ll a,b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        f();
        for(auto e:jew_vec) cout << ans[e] << " ";
        cout << "\n";
    }
}

/*
2
4 2
1 3 2 4
1 3
0 1
0 3
3 2
3 4
9 3
2 3 7 4 6 8 9 1 5
1 7 2
0 3
2 9
6 7
4 8
2 1
0 6
4 2
9 5
0 4
*/