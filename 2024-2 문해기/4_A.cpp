#include <iostream>
#include <unordered_map>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 987654321
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000009;

unordered_map<string,ll> um;
unordered_map<string,ll> um2;

int main() {
    FIO;
    ll tc; cin >> tc;
    while(tc--){
        um.clear(), um2.clear();
        ll n; cin >> n;
        ll sa=0, sb=0;
        ll prev_a = 0,prev_b = 0;
        for(ll i=0;i<n;i++){
            ll a,b; string s;
            cin >> a >> b >> s;
            if(a > prev_a) {
                if(um.find(s) != um.end()) um[s] += (a - prev_a);
                else um.insert({s, a - prev_a});
                sa += (a - prev_a);
            }
            if(b > prev_b){
                if(um2.find(s) != um2.end()) um2[s] += (b - prev_b);
                else um2.insert({s, b - prev_b});
                sb += (b - prev_b);
            }
            prev_a = a, prev_b = b;
        }

        pair<string, ll> ans = {"", -1};
        if(sa > sb) {
            for(auto e:um) if(ans.second < e.second) ans = e;
        }
        else {
            for(auto e:um2) if(ans.second < e.second) ans = e;
        }
        cout << ans.first << " " << ans.second << "\n";
    }
}


/*
2
3
2 0 sanghun
2 3 yeongjin
5 3 junho
6
3 0 integer
6 0 double
6 3 boolean
6 5 character
6 7 string
6 9 float

*/