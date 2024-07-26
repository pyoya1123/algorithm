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
int _map[105][105];
int r,c,m1,m2,m3,m4,dir;
vector<pair<int,int>> vec;
vector<int> values;
int _dir[2] = {1,-1};

int main() {
    FIO;

    cin >> n;
    for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            cin >> _map[y][x];
        }
    }
    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;

    vec.push_back({r,c});
    values.push_back(_map[r][c]);

    int cur_y = r, cur_x = c;
     // 1번 방향
     for(int d=0;d<m1;d++){
        cur_y--;
        cur_x++;
        values.push_back({_map[cur_y][cur_x]});
        vec.push_back({cur_y,cur_x});
     }

     // 2번 방향
     for(int d=0;d<m2;d++){
        cur_y--;
        cur_x--;
        values.push_back({_map[cur_y][cur_x]});
        vec.push_back({cur_y,cur_x});
     }

     // 3번 방향
     for(int d=0;d<m3;d++){
        cur_y++;
        cur_x--;
        values.push_back({_map[cur_y][cur_x]});
        vec.push_back({cur_y,cur_x});
     }

     // 4번 방향
     for(int d=0;d<m4-1;d++){
        cur_y++;
        cur_x++;
        values.push_back({_map[cur_y][cur_x]});
        vec.push_back({cur_y,cur_x});
     }

    // dir == 1이면 왼쪽으로 쉬프트, 0이면 오른쪽으로 쉬프트 
    
    int tmp = values[0];
    int p = 0;
    do {
        int next_p = p - _dir[dir];
        if(next_p >= (int)values.size()) next_p = 0;
        if(next_p < 0) next_p = (int)values.size() - 1;
        values[p] = values[next_p];
        p = next_p;
    }while(p != 0);

    if(dir == 0) values[1] = tmp;
    else values[(int)values.size()-1] = tmp;

    for(int i=0;i<vec.size();i++){
        _map[vec[i].first][vec[i].second] = values[i];
    }


    for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            cout << _map[y][x] << " ";
        }
        cout << "\n";
    }
}