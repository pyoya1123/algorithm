#include <iostream>
using namespace std;
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX 987654321
#define FIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int n;
int m[22][22];
int dir_y[4] = {-1,-1,1,1}; // 오른쪽 위 대각선, 왼쪽 위 대각선, 왼쪽 아래 대각선, 오른쪽 아래 대각선 
int dir_x[4] = {1,-1,-1,1};
int ans = 0;

void f(int srt_y, int srt_x, int cur_y, int cur_x, int dir, int sum) {
    if(srt_y == cur_y && srt_x == cur_x && sum != 0){
        ans = max(ans, sum);
        return;
    }
    // 더 갈건지,
    int dy = cur_y + dir_y[dir];
    int dx = cur_x + dir_x[dir];
    if(!(dy > n || dy < 1 || dx > n || dx < 1)) {
        f(srt_y, srt_x, dy, dx, dir, sum + m[cur_y][cur_x]);
    }
    // 꺾을 건지
    if(dir != 3){
        dy = cur_y + dir_y[(dir+1)%4];
        dx = cur_x + dir_x[(dir+1)%4];
        if(!(dy > n || dy < 1 || dx > n || dx < 1)) {
            f(srt_y, srt_x, dy, dx, (dir+1)%4, sum + m[cur_y][cur_x]);
        }
    }
}

int main() {
    FIO;

    cin >> n; for(int y=1;y<=n;y++) for(int x=1;x<=n;x++) cin >> m[y][x];

    for(int y=3;y<=n;y++){
        for(int x=1;x<=n;x++){
            f(y,x,y,x,0,0);
        }
    }

    cout << ans << "\n";
}