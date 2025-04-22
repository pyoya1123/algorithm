#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 987654321
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000009;

ll getQuater(ll y, ll x, ll n) {
    ll t = (ll)pow(2,n);
    if(y < t/2 && x < t/2) return 1;
    else if(y < t/2 && x >= t/2) return 2;
    else if(y >= t/2 && x < t/2) return 3;
    else return 4;
}

ll getQuater2(ll v, ll n, ll srt) {
    ll t = (ll)pow(2,2 * n);
    if(v <= t/4 + srt) return 1;
    else if(v <= 2 * (t/4) + srt) return 4;
    else if(v <= 3 * (t/4) + srt) return 3;
    else return 2;
}

pair<ll, ll> f2(ll v, ll n, ll srt) {
    if(n==0) return{1,1};
    pair<ll, ll> ret = {0,0};
    ll q = getQuater2(v,n,srt);
    ll p = (ll)pow(2, 2 * n);
    ll pp = (ll)pow(2,n);
    if(q == 1) {
        pair<ll,ll> t = f2(v, n-1, srt);
        ret.first += t.first;
        ret.second += t.second;
    }
    else if(q == 2) {
        pair<ll,ll> t = f2(v, n-1, srt + 3 * (p/4));
        ret.first += t.first;
        ret.second += t.second + (pp/2);
    }
    else if(q == 3) {
        pair<ll,ll> t = f2(v, n-1, srt + 2 * (p/4));
        ret.first += t.first + (pp/2);
        ret.second += t.second;
    }
    else {
        pair<ll,ll> t = f2(v, n-1, srt + p/4);
        ret.first += t.first + (pp/2);
        ret.second += t.second + (pp/2);
    }
    return ret;
}

ll f(ll y, ll x, ll n) {
    if(n == 0) return 1;
    ll q = getQuater(y,x,n);
    ll p = (ll)pow(2,2*n-2);
    ll pp = (ll)pow(2,n);
    ll ret = 0;
    if(q == 1) ret += f(y,x,n-1);
    else if(q == 2) ret += f(y,x-(pp/2),n-1) + 3 * p;
    else if(q == 3) ret += f(y-(pp/2),x,n-1) + 2 * p;
    else ret += f(y-(pp/2),x-(pp/2),n-1) + p;
    return ret;
}

int main() {
    FIO;
    ll tc; cin >> tc;
    while(tc--) {
        ll n,q; cin >> n >> q;
        cin.ignore();
        while(q--){
            string s;
            getline(cin, s); 
            string token;
            istringstream iss(s);
            vector<string> tokens;
            while(getline(iss, token, ' ')) {
                if(!token.empty()) tokens.push_back(token);
            }
            if(tokens[0].compare("->") == 0) {
                ll y = stoll(tokens[1]) - 1;
                ll x = stoll(tokens[2]) - 1;
                ll c = f(y,x,n);
                cout << c << "\n";
            }  
            else {
                pair<ll,ll> t = f2(stoll(tokens[1]), n, 0);
                cout << t.first << " " << t.second << "\n";
            }
        }
    }
}