#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;

ll N, M;
vector<pair<ll,ll> > vec;
ll sum[100005];
ll parent[100005];
ll dp[100005];

int main() {
    FIO;
    
    cin >> N >> M;

    for(int i=0;i<=N;i++) parent[i] = i;

    ll ans = __LONG_LONG_MAX__;

    for(int i=0;i<N;i++){
        ll a,b;
        cin >> a >> b;
        vec.push_back(make_pair(a,b));
        dp[i] = a;
        if(a >= M) ans = min(ans,b);
    }

    ll l=0, r=1;
    ll sum = vec[l].first;
    ll _max = vec[l].second;
    ll _max_idx = l;
    while(r < N){
        if(sum >= M){
            ans = min(ans, _max);
            l=_max_idx+1;
            sum = 0;
            _max = 0;
            for(ll i=l;i<=min(N-1, r);i++) {
                sum += vec[i].first;
                if(vec[i].second > _max){
                    _max = vec[i].second;
                    _max_idx = i;
                }
            }
            continue;
        }
        else {
            sum += vec[r].first;
            if(_max < vec[r].second) {
                _max = vec[r].second;
                _max_idx = r;
            }
        }

        r++;
    }

    cout << ans << "\n";
}