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
vector<bool> a[2];

vector<int> failure(vector<bool> &s){    
    vector<int> f(s.size());
    int j = 0;
    for(int i=1;i<s.size();i++){
        while(j > 0 && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

int main() {
    FIO;
    
    a[0].resize(720001), a[1].resize(360000);

    cin >> n;
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            int input; cin >> input;
            a[i][input] = true;
        }
    }
    for(int j=0;j<720000;j++) a[0][j] = a[0][j%360000];

    vector<int> f = failure(a[1]);
    int j = 0;
    int ans = 0;
    for(int i=0;i<a[0].size();i++){
        while(j > 0 && a[0][i] != a[1][j]) j = f[j-1];
        if(a[0][i] == a[1][j]) ++j;
        if(j == a[1].size()) {
            ans = 1;
            break;
        }
    }
    cout << (ans == 0 ? "impossible\n" : "possible\n");
}