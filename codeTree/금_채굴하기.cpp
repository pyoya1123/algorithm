#include <iostream>
using namespace std;
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX 987654321

class node {
    public:
        int y;
        int x;
        int dis;
        node() {}
        node(int y, int x, int dis):y(y), x(x), dis(dis) {}
};

int n,m;
int _map[22][22];
bool v[22][22];
bool v1[22][22];
int tmp_gold_cnt = 0;
int ans = 0;

int dir_y[4] = {-1,1,0,0};
int dir_x[4] = {0,0,-1,1};

void bfs(int y, int x,int dis) {
    queue<node> q;
    q.push(node(y,x,dis));
    while(!q.empty()){
        node t = q.front(); q.pop();
        if(!v[t.y][t.x] && _map[t.y][t.x] == 1) tmp_gold_cnt++;
        v[t.y][t.x] = true;
        if(t.dis == 0) continue;
        for(int dir=0;dir<4;dir++) {
            int dy = t.y + dir_y[dir];
            int dx = t.x + dir_x[dir];
            if(dy > n || dy < 1 || dx > n || dx < 1) continue;
            if(v1[dy][dx]) continue;
            v1[dy][dx] = true;
            q.push(node(dy,dx,t.dis-1));
        }
    }
}

int main() {
    cin >> n >> m;
    for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            cin >> _map[y][x];
        }
    }

    for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            tmp_gold_cnt = 0;
            memset(v, false, sizeof(v));
            for(int k=0;k<=2*n;k++){    
                memset(v1, false, sizeof(v1));
                v1[y][x] = true;
                bfs(y,x,k);
                if(tmp_gold_cnt * m >= (k*k+(k+1)*(k+1))) ans = max(ans, tmp_gold_cnt);
            }
        }
    }

    cout << ans << "\n";
}