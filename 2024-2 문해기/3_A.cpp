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

bool isMix(string s, ll l, ll r){
    for(ll i=l+1;i<=r;i++) if(s[i] != s[i-1]) return true;
    return false;
}

void f(string s, ll l, ll r) {
    if(l==r) {
        cout << s[l];
        return;
    }
    if(isMix(s,l,r)) {
        cout << "B";
        ll mid = (l+r)/2;
        f(s,l,mid);
        f(s,mid+1,r);
    }
    else cout << s[l];
}

int main() {
    FIO;
    ll tc; cin >> tc;
    while(tc--){
        string s; cin >> s;
        f(s,0,s.size()-1);
        cout << "\n";
    }
}