#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 987654321
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;

int main() {
    FIO;
    ll tc; cin >> tc;
    while(tc--){
        ll x,y; cin >> x >> y; // x -> destroy cost
        string s; cin >> s;
        vector<ll> cnt(3);
        ll con = 0, ans = 0;
        for(auto e:s){
            if(e == '3' || e == '6' || e == '9') {
                ans += min(con * x, y + x);
                con = 0;
                cnt[(e-'0')/3 - 1]++;
            }
            else con++;
        }
        if(con >= 1) ans += min(con * x, y + x);
        cout << ans << " " << min(cnt[0], min(cnt[1],cnt[2])) << "\n";
    }
}

/*
3
1 2
1234567890
2 3
999444336677
4 2
33446688999
*/