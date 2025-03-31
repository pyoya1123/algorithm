#include <iostream>
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
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;

int n;
bool v[22];
vector<int> temp;
vector<int> ans;
int arr[22][6];
int _min = INT_MAX;
int bound[4];
int mp,mf,ms,mv;

bool isDictFirst() {
    for(int i=0;i<min((int)ans.size(),(int)temp.size());i++){
        if(ans[i] > temp[i]) return true;
        else if(ans[i] < temp[i]) return false;
    }
    return false;
}

void f(int idx, int cnt, int b) {
    if(cnt >= b) {
        int sum = 0;
        vector<int> tmp_m(4,0);
        for(int i=0;i<temp.size();i++) {for(int j=0;j<4;j++) {tmp_m[j] += arr[temp[i]][j];} sum += arr[temp[i]][4];}
        for(int i=0;i<4;i++) if(tmp_m[i] < bound[i]) return;
        if(sum < _min){
            _min = sum;
            ans.clear();
            for(auto e:temp) ans.push_back(e);
        }  
        else {
            if(sum == _min && isDictFirst()) {
                ans.clear();
                ans = temp;
            }
        }
        return;
    }

    for(int i=idx;i<n;i++){
        if(v[i]) continue;
        v[i] = true;
        temp.push_back(i);
        f(i+1,cnt+1,b);
        temp.pop_back();
        v[i] = false;
    }
}

int main() {
    FIO;
    cin >> n;
    for(int i=0;i<4;i++) cin >> bound[i];
    for(int i=0;i<n;i++) for(int j=0;j<5;j++) cin >> arr[i][j];
    for(int i=1;i<=n;i++) f(0,0,i);
    sort(ans.begin(),ans.end());
    _min = (_min == INT_MAX) ? -1 : _min;
    cout << _min << "\n";
    for(auto e:ans) cout << e + 1 << " ";
}


/*
5

6 6 6 6

3 3 3 3 3

2 2 2 2 2

2 2 2 2 2

3 3 3 3 3

2 2 2 2 2

*/