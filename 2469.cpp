#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;

int k, n;
string bound;
string m[1005];
int q;

int u[1005][33];
int d[1005][33];

bool v[33];

int main() {
    FIO;
    
    cin >> k >> n;
    cin >> bound;

    for(int i=0;i<n;i++) {
        cin >> m[i];
        if(m[i][0] == '?') q = i;
    }

    for(int x=-1;x<k-1;x++){
        int c = ((x+1) + 65);
        int y = 0;
        int cur_x = x;
        while(y<q){
            if(cur_x < 0) {
                if(m[y][cur_x+1] == '-') cur_x++;
            }
            else if(cur_x >= k-1){
                if(m[y][cur_x-1] == '-') cur_x--;
            }
            else {
                if(m[y][cur_x] == '-') cur_x--;
                else if(m[y][cur_x+1] == '-') cur_x++;
            }
            y++;
        }
        u[y-1][cur_x+1] = c;
    }

    for(int x=-1;x<k-1;x++) {
        int c = (int)bound[x+1];
        int y = n-1;
        int cur_x = x;
        while(y > q) {
            if(cur_x < 0) {
                if(m[y][cur_x+1] == '-') cur_x++;
            }
            else if(cur_x >= k-1){
                if(m[y][cur_x-1] == '-') cur_x--;
            }
            else {
                if(m[y][cur_x] == '-') cur_x--;
                else if(m[y][cur_x+1] == '-') cur_x++;
            }
            y--;
        }
        d[y+1][cur_x+1] = c;
    }

    bool temp = true;

    for(int i=0;i<k-1;i++){
        if(u[q-1][i] != d[q+1][i]){
            if(i > 0) {
                if(v[i-1]) {
                    temp = false;
                    break;
                }
                else {
                    v[i] = true;
                    int tmp = u[q-1][i];
                    u[q-1][i] = u[q-1][i+1];
                    u[q-1][i+1] = tmp;
                }
            }
            else {
                v[i] = true;
                int tmp = u[q-1][i];
                u[q-1][i] = u[q-1][i+1];
                u[q-1][i+1] = tmp;
            }
        }
    }

    if(temp) {
        for(int i=0;i<k-1;i++) {
            if(v[i]) cout << "-";
            else cout << "*";
        }
    }
    else {
        for(int i=0;i<k-1;i++) cout << "x";
    }

}