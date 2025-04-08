#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
#include <cctype>
#include <stack>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <deque>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;
typedef long double ld;

int n;
string m[5];
vector<int> temp[11];
ld sum[11];
ll cnt[11];

string bound[10][5] = {
{
    "###",
    "#.#",
    "#.#",
    "#.#",
    "###",
},
{
    "..#",
    "..#",
    "..#",
    "..#",
    "..#",
},
{
    "###",
    "..#",
    "###",
    "#..",
    "###",
},
{
    "###",
    "..#",
    "###",
    "..#",
    "###",
},
{
    "#.#",
    "#.#",
    "###",
    "..#",
    "..#",
},
{
    "###",
    "#..",
    "###",
    "..#",
    "###",
},
{
    "###",
    "#..",
    "###",
    "#.#",
    "###",
},
{
    "###",
    "..#",
    "..#",
    "..#",
    "..#",
},
{
    "###",
    "#.#",
    "###",
    "#.#",
    "###",
},
{
    "###",
    "#.#",
    "###",
    "..#",
    "###",
},
};

bool isMatching(int p, int num) {
    for(int y=0;y<5;y++){
        for(int x=p,j=0;x<p+3,j<3;x++,j++){
            if(m[y][x] == '.') continue;
            if(m[y][x] == '#' && m[y][x] != bound[num][y][j]) return false;
        }
    }
    return true;
}

int main() {
    FIO;

    cin >> n;
    for(int y=0;y<5;y++) cin >> m[y];

    int temp_idx = 0;

    for(int i=0;i<n;i++){
        int p = i*4;
        for(int num=0;num<=9;num++) if(isMatching(p,num)) temp[temp_idx].push_back(num);
        if(!temp[temp_idx].empty()) temp_idx++;
        else {
            cout << -1;
            return 0;
        }
    }

    for(int i=temp_idx-1, p=0;i>=0;i--,p++){
        for(auto e:temp[i]) {
            sum[i] += ((double)pow(10, p) * e * ((i != temp_idx-1 ? cnt[i+1] : 1)) + (i != temp_idx-1 ? sum[i+1] : 0));
            cnt[i] += (i != temp_idx-1 ? cnt[i+1] : 1);
        }
    }

    if(cnt[0] == 0) cout << -1;
    else {
        cout.precision(5);
        cout << fixed << (double)sum[0] / cnt[0];
    }
}

/*
2 
###....
#.#..#.
###..#.
#.#..#.
###..#.

위와 같이 아예 잘못켜진 곳이 있으면 안내판으로 숫자를 표시할 수가 없음. 
이 경우 가능한 층 번호가 없음. 
*/