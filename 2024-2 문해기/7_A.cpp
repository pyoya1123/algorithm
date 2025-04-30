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

ll dir_y[4] = {-1,1,0,0};
ll dir_x[4] = {0,0,-1,1};

struct node {
    ll y;
    ll x;
    ll cost;
};

int main() {
    FIO;
    ll tc; cin >> tc;
    while(tc--){
        ll N,M; cin >> M >> N; // width, height
        ll start_x, start_y, end_x, end_y; cin >> start_x >> start_y >> end_x >> end_y;
        vector<vector<char>> m(N+1,vector<char>(M+1));
        for(ll y=0;y<N;y++) for(ll x=0;x<M;x++) cin >> m[y][x];
        // for(ll x=0;x<M;x++) for(ll l=0,r=N-1;l<r;l++,r--) swap(m[l][x],m[r][x]);
        for(ll l=0,r=N-1;l<r;l++,r--) swap(m[l],m[r]); // 위랑 같은 로직인데 ,이것도 맞는 문법이고 더 간단함.
        vector<vector<ll>> dp(N+1, vector<ll>(M+1, MAX));
        dp[start_y][start_x] = 0;
        queue<node> q; q.push({start_y, start_x, 0});
        while(!q.empty()){
            node t = q.front(); q.pop();
            for(ll dir=0;dir<4;dir++){
                ll dy = t.y + dir_y[dir];
                ll dx = t.x + dir_x[dir];
                if(dy >= N || dy < 0 || dx >= M || dx < 0) continue;
                if(m[dy][dx] == 'X') continue;
                if(dp[dy][dx] <= t.cost + 1) continue;
                dp[dy][dx] = t.cost + 1;
                q.push({dy,dx,t.cost + 1});
            }
        }
        cout << (dp[end_y][end_x] == MAX ? -1 : dp[end_y][end_x]) << "\n";
    }
}

/*
2
5 4
1 2 4 1
X O O O X
O O X O X
O X X O O 
X O O X O
3 4
0 3 2 3
O X O
O O X
O O O
O O O
*/