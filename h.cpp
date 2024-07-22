#include <iostream>
using namespace std;
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX 987654321

int N,M;
int m[55][55];
int dp[55][55];
int dir_y[8] = {-1,-1,0,1,1,1,0,-1};
int dir_x[8] = {0,-1,-1,-1,0,1,1,1};
int ans[55][55];

class node {
    public:
        int y;
        int x;
        int cost;
        node() {}
        node(int y, int x, int cost):y(y),x(x),cost(cost){}
};

int main() {
    fill(&ans[0][0], &ans[0][0] + 55*55, MAX);
    cin >> N >> M;
    for(int y=1;y<=N;y++){
        for(int x=1;x<=M;x++){
            cin >> m[y][x];
        }
    }

    for(int y=1;y<=N;y++){
        for(int x=1;x<=M;x++){
            if(m[y][x] == 1){
                fill(&dp[0][0], &dp[0][0] + 55*55,MAX);
                queue<node> q;
                q.push(node(y,x,0));
                dp[y][x] = 0;
                while(!q.empty()){
                    node t = q.front(); q.pop();
                    for(int dir=0;dir<8;dir++){
                        int dy = t.y + dir_y[dir];
                        int dx = t.x + dir_x[dir];
                        if(dp[dy][dx] <= t.cost + 1) continue;
                        if(m[dy][dx] == 1) continue;
                        if(dy > N || dy < 1 || dx > M || dx < 1) continue;
                        dp[dy][dx] = t.cost + 1;
                        q.push(node(dy,dx,t.cost+1));
                    }
                }
                for(int yy=1;yy<=N;yy++){
                    for(int xx=1;xx<=M;xx++){
                        if(m[yy][xx] == 0){
                            ans[yy][xx] = min(ans[yy][xx], dp[yy][xx]);
                        }
                    }
                }
            }
        }
    }

    int min_dis = 0;
    for(int y=1;y<=N;y++){
        for(int x=1;x<=M;x++){
            if(m[y][x] == 1) continue;
            min_dis = max(min_dis, ans[y][x]);
        }
    }
    
    cout << min_dis << "\n";
}