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

struct Mat {
    ll m[2][2];
};

Mat defaultMat;

Mat getMultiply(const Mat& a, const Mat& b){
    Mat res{};
    for(ll y=0;y<2;y++){
        for(ll x=0;x<2;x++){
            for(ll e=0;e<2;e++){
                res.m[y][x] += (a.m[y][e] * b.m[e][x]) % MOD;
                res.m[y][x] %= MOD;
            }
        }
    }
    return res;
}

Mat f(ll n) {
    if(n == 0 || n == 1) return defaultMat;
    Mat tmp = f(n/2);
    Mat res = getMultiply(tmp, tmp);
    if(n % 2 != 0) res = getMultiply(res, defaultMat);
    return res;
}

int main() {
    FIO;
    ll tc; cin >> tc;
    while(tc--){
        for(ll y=0;y<2;y++) for(ll x=0;x<2;x++) cin >> defaultMat.m[y][x];
        ll n; cin >> n;
        Mat res = f(n);
        for(ll y=0;y<2;y++){
            for(ll x=0;x<2;x++) cout << res.m[y][x] << " ";
            cout << "\n";
        }
    }
}

/*
2
3 1
4 2
31
2 0
0 1
1000000000
*/