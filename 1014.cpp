#include <iostream>
#include <string.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int tc;
string _map[11];
int dp[11][1025]; // dp[i][j] -> i번째 y에서, 비트 값이 w일 때 최대값
int N, M;

// 왼쪽 대각선, 오른쪽 대각선 체크 
bool check_digonal(int y, int j, int w) {
    if(M==1) return true;
    if(y - 1 < 0) return true; // 첫번째 높이라면, 그 위 컨닝 요소를 고려할 필요 x
    for(int i=0;(1 << i) <= j;i++) {
        if(!(j & (1 << i))) continue;
        // 왼쪽 대각선만 고려 
        if(i == 0) {
            if((w&(1<<(i+1))) && (_map[y-1][(M-1) - (i+1)] == 'x')) return false;
            if(w & (1<<(i+1))) return false;
            if(_map[y-1][(M-1) - (i+1)] == 'x') continue;
            if(!(w & (1<<(i+1)))) continue;   
        }
        else {
            // 오른쪽 대각선만 고려
            if(i == M-1){
                if((w&(1<<(i-1))) && (_map[y-1][(M-1)-(i-1)] == 'x')) return false;
                if(w & (1<< (i-1))) return false;
                if(_map[y-1][(M-1) - (i-1)] == 'x') continue;
                if(!(w & (1<<(i-1)))) continue;
            }
            // 양쪽 대각선 고려 
            else {
                if(((w & (1<<(i-1))) && _map[y-1][(M-1)-(i-1)] == 'x') || (((w & (1<<(i+1))) && _map[y-1][(M-1)-(i+1)] == 'x'))) return false;
                if((w & (1 << (i-1))) || (w & (1 << (i+1)))) return false;
                if((_map[y-1][(M-1)-(i+1)] == 'x' || !(w & (1<<(i+1)))) && (_map[y-1][(M-1)-(i-1)] == 'x' || !(w & (1<<(i-1))))) continue;
            }
        }
    }

    return true;
}

// 수평 체크
bool check_horizontal(int y, int b) {
    if((b&1) && (_map[y][M-1]) == 'x') return false;
    for(int i=0;(1<<(i+1))<=b;i++) {
        if(((b & (1<<i)) && _map[y][(M-1) - i] == 'x') || ((b & (1<<(i+1))) && _map[y][(M-1) - (i+1)] == 'x')) return false;
        if((b & (1<<i)) && (b & (1<<(i+1)))) return false;
    }
    return true;
}

int getCnt(int y, int b){
    int res = 0;
    for(int i=0;(1<<i) <= b;i++) if(_map[y][(M-1) - i] != 'x' && (b & (1<<i))) res++;
    return res;
}

int main() {
    FIO;

    cin >> tc;

    while(tc--){
        memset(dp, 0, sizeof(dp));
        cin >> N >> M;
        for(int y=0;y<N;y++) cin >> _map[y];
        for(int y=0;y<N;y++){
            for(int j = 0;j < (1<<M);j++){ // 현재 높이의 비트마스킹
                if(!check_horizontal(y, j)) continue;
                int cnt = getCnt(y,j);
                for(int w = 0;w < (1<<M);w++) { // w는 현재 높이보다 하나 더 높은 높이의 비트마스킹
                    if(!check_digonal(y,j,w)) continue;
                    if(y==0) {
                        dp[y][j] = cnt;
                    }
                    else {
                        dp[y][j] = max(dp[y][j], dp[y-1][w] + cnt);
                    }
                }
            }
        }

        int ans = 0;
        int prev_sum = 0;
        int sum = 0;
        for(int y=0;y<N;y++){
            sum = 0;
            for(int i=0;i<(1<<M);i++) {
                sum = max(sum, dp[y][i]);
            }
            if(sum == 0) ans += prev_sum;
            prev_sum = sum;
        }
        ans += prev_sum;
        cout << ans << "\n";
    }
}