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

int main() {
    FIO;
    ll tc; cin >> tc;
    while(tc--){
        ll h,q; cin >> h >> q;
        for(ll i=0;i<q;i++){
            ll input; cin >> input;
            string ans = "";
            while(input > 1) {
                if(input % 2 == 0) ans += "L";
                else ans += "R";
                input /= 2;
            }
            reverse(ans.begin(), ans.end());
            cout << ans << "\n";
        }
        
    }
}

/*
2
3 2
6
10
2 2
3
5
*/