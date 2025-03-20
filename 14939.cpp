#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

string m[11];
string temp_m[11];

int dir_y[4] = {-1,1,0,0};
int dir_x[4] = {0,0,-1,1};

int ans = INT_MAX;

void print_temp_m() {
    for(int y=0;y<10;y++) cout << temp_m[y] << "\n";
    cout << "\n";
}

void init(){
    for(int y=0;y<10;y++) temp_m[y] = "##########";
}

int turnOnBit(int y, int bit) {
    int res = 0;
    for(int i=0;i<10;i++){
        if(bit & (1<<i)){
            res++;
            temp_m[y][(9-i)] = (temp_m[y][(9-i)] == '#') ? 'O' : '#';
            for(int dir=0;dir<4;dir++) {
                int dy = dir_y[dir] + y;
                int dx = dir_x[dir] + (9-i);
                if(dy >= 10 || dy < 0 || dx >= 10 || dx < 0) continue;
                temp_m[dy][dx] = (temp_m[dy][dx] == '#') ? 'O' : '#';
            }
        }
    }
    return res;
}

void turnOn(int y, int x) {
    temp_m[y][x] = (temp_m[y][x] == '#') ? 'O' : '#';
    for(int dir=0;dir<4;dir++) {
        int dy = dir_y[dir] + y;
        int dx = dir_x[dir] + x;
        if(dy >= 10 || dy < 0 || dx >= 10 || dx < 0) continue;
        temp_m[dy][dx] = (temp_m[dy][dx] == '#') ? 'O' : '#';
    }
}

bool check(int yy) {
    for(int y=0;y<=yy;y++) {
        for(int x=0;x<10;x++) if(m[y][x] != temp_m[y][x]) return false;
    }
    return true;
}

void f(int y, int cnt) {
    if(y >= 10){
        if(check(9)) ans = min(ans, cnt);
        return;
    }

    if(y > 2){
        if(!check(y-2)) return;
    }

    int temp_cnt = 0;

    for(int x=0;x<10;x++){
        if(m[y-1][x] != temp_m[y-1][x]){
            turnOn(y,x);
            temp_cnt++;
        }
    }
    f(y+1,cnt+temp_cnt);
}

int main() {
    FIO;
    for(int y=0;y<10;y++) cin >> m[y];


    for(int i=0;i<1024;i++){
        init();
        int t = turnOnBit(0,i);
        f(1, t);
    }

    
    cout << (ans == INT_MAX ? -1 : ans) << "\n";
}


/*

int turnOnBit(int y, int bit) {
    int res = 0;
    for(int i=0;i<10;i++){
        if(bit & (1<<i)){
            res++;
            temp_m[y][(9-i)] = (temp_m[y][(9-i)] == '#') ? 'O' : '#';
            for(int dir=0;dir<4;dir++) {
                int dy = dir_y[dir] + y;
                int dx = dir_x[dir] + (9-i);
                if(dy >= 10 || dy < 0 || dx >= 10 || dx < 0) continue;
                temp_m[dy][dx] = (temp_m[dy][dx] == '#') ? 'O' : '#';
            }
        }
    }
    return res;
}

이 함수에서 if(bit & (1<<i)) 부분을 잘못 작성해서 헤맴.
if(bit & i) 가 아님.

*/