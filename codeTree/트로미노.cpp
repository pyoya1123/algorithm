#include <iostream>
using namespace std;
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX 987654321

int n,m;
int _map[202][202];

int dir[6][3][2][2] = {
    {{{1,0},{1,1}}, {{-1,0},{0,1}}, {{0,-1},{-1,-1}}},
    {{{1,0},{1,-1}}, {{-1,0},{0,-1}}, {{0,1},{-1,1}}},
    {{{0,1},{1,1}}, {{0,-1},{1,0}}, {{-1,0},{-1,-1}}},
    {{{0,-1},{1,-1}}, {{0,1},{1,0}}, {{-1,0},{-1,1}}},
    {{{0,1},{0,2}}, {{0,-1},{0,1}}, {{0,-1},{0,-2}}},
    {{{1,0},{2,0}}, {{-1,0},{1,0}}, {{-1,0},{-2,0}}}
};

int ans = 0;

bool check(int y, int x, int i, int j) {
    for(int e=0;e<2;e++){
        int dy = y + dir[i][j][e][0];
        int dx = x + dir[i][j][e][1];
        if(dy > n || dy < 1 || dx > m || dx < 1) return false;
    }
    return true;
}

int getSum(int y, int x, int i, int j) {
    int res = _map[y][x];
    for(int e=0;e<2;e++){
        int dy = y + dir[i][j][e][0];
        int dx = x + dir[i][j][e][1];
        res += _map[dy][dx];
    }
    return res;
}

void f() {
    for(int y=1;y<=n;y++){
        for(int x=1;x<=m;x++){
            for(int i=0;i<6;i++){
                for(int j=0;j<3;j++){
                    if(check(y,x,i,j)){
                        int t = getSum(y,x,i,j);
                        ans = max(ans, t);
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int y=1;y<=n;y++){
        for(int x=1;x<=m;x++){
            cin >> _map[y][x];
        }
    }

    f();

    cout << ans << "\n";
}