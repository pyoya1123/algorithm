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

const ll MOD = 1000000007;
vector<pair<ll,ll>> vec;
ll dp[1005][22][22]; // white, black

int main() {
    FIO;

    ll w,b; while(cin >> w && cin >> b) vec.push_back({w,b});

    dp[0][1][0] = vec[0].first, dp[0][0][1] = vec[0].second;

    for(ll i=1;i<vec.size();i++){
        for(ll w=0;w<=min(i,15LL);w++){ // selected cnt 
            for(ll b=0;b<=min(i,15LL);b++){
                dp[i][w][b] = max(dp[i][w][b], dp[i-1][w][b]);
                if(w < 15) dp[i][w+1][b] = max(dp[i][w+1][b], dp[i-1][w][b] + vec[i].first);
                if(b < 15) dp[i][w][b+1] = max(dp[i][w][b+1], dp[i-1][w][b] + vec[i].second);
            }
        }
    }

    cout << dp[vec.size()-1][15][15];
}