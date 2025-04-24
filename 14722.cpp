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
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 987654321
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000009;

ll N;
ll m[1005][1005];
ll dir_y[2] = {1,0};
ll dir_x[2] = {0,1};
ll dp[1005][1005];

struct node {
    ll y;
    ll x;
    ll milk;
    ll drinkMilkCnt;
};

ll canDrink(ll prev, ll cur){
    return prev % 3 == cur;
}

int main() {
    FIO;
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for(ll y=1;y<=N;y++) for(ll x=1;x<=N;x++) cin >> m[y][x];

    dp[1][1] = (m[1][1] == 0);
    ll ans = dp[1][1];

    for(ll x=2;x<=N;x++){
        dp[1][x] = max(dp[1][x], dp[1][x-1]);
        if(canDrink(dp[1][x-1], m[1][x])) dp[1][x] = max(dp[1][x], dp[1][x-1] + 1);
    }
    for(ll y=2;y<=N;y++){
        dp[y][1] = max(dp[y][1], dp[y-1][1]);
        if(canDrink(dp[y-1][1], m[y][1])) dp[y][1] = max(dp[y][1], dp[y-1][1] + 1);
    }


    for(ll y=2;y<=N;y++){
        for(ll x=2;x<=N;x++){
            dp[y][x] = max(dp[y][x], max(dp[y-1][x], dp[y][x-1]));
            if(canDrink(dp[y-1][x], m[y][x])) dp[y][x] = max(dp[y][x], dp[y-1][x] + 1);
            if(canDrink(dp[y][x-1], m[y][x])) dp[y][x] = max(dp[y][x], dp[y][x-1] + 1);
        }
    }

    cout << dp[N][N];
}

/*
0 -> 1 -> 2 -> 0 이런 순으로 먹어야 하기 때문에, 
dp에 저장되는 최대값을 이용해서, 해당 값이 지금까지 먹은 우유 값이고, 동시에 마지막에 먹은 우유가 무엇인지까지 알 수 있음
*/