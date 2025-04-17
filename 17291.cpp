#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
#include <cctype>
#include <stack>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <deque>
#include <iomanip>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 987654321
typedef long long ll;
typedef long double ld;

int main() {
    FIO;

    ll N; cin >> N;

    vector<vector<ll>> dp(33, vector<ll>(14));
    dp[1][4] = 1;

    for(ll i=2;i<=N;i++){
        vector<vector<ll>> tmp(33, vector<ll>(14));
        for(ll j=5;j>=2;j--) tmp[i][4 + (i%2==0)] += dp[i-1][j];            
        for(ll j=0;j<=5;j++) tmp[i][j] += dp[i-1][j+1];
        for(ll j=1;j<=5;j++) dp[i][j] = tmp[i][j];
    } 
    cout << dp[N][2] + dp[N][3] + dp[N][4] + dp[N][5];

}