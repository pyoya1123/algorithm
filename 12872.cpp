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
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 987654321
typedef long long ll;
typedef long double ld;

// #define MOD 1000000007

const ll MOD = 1000000007;

ll dp[105][105]; // dp[i][j] -> i번째 인덱스까지 서로 다른 원소의 개수가 j

int main() {
    FIO;

    ll N,M,P; cin >> N >> M >> P;
    dp[0][0] = 1;
    for(ll i=1;i<=P;i++){
        for(ll j=1;j<=N;j++){
            dp[i][j] = (dp[i][j] + dp[i-1][j-1] * (N-j+1)) % MOD;
            if(j > M) dp[i][j] = (dp[i][j] + dp[i-1][j] * (j - M)) % MOD;
        }
    }

    cout << dp[P][N] % MOD;
}

/*

a x x x x a 
이런식으로 있을 때, a 사이에 있는 곡들은 모두 서로 다른 M 개의 곡이어야함. 이게 최소 조건이고, 
저 a ~ a 양 옆에 중복되는 원소들을 더 붙인다고 할 때 최소 M개의 곡 이상이 필요하다는거임.
즉, 중간에는 최소 M개의 서로 다른 곡이 존재하고, 그 이후에 더 나아갈 때, 그 이상의 곡들이 필요하다는 의미임.

*/