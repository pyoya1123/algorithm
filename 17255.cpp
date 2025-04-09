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

ll dp[9];
unordered_set<string> sset[9];
string s; 

void dfs(string cur, ll l, ll r) {
    sset[cur.size()].insert(cur);
    if(l >= 0) dfs(s[l] + cur, l-1, r);
    if(r < s.size()) dfs(cur + s[r], l, r+1);
}

ll getAns(string cur) {
    if(cur.size() <= 1) return 1;
    ll ret = 0;
    for(auto e:sset[cur.size()-1]) if(cur.find(e) != string::npos) ret += getAns(e);
    return ret;
}

int main() {
    FIO;
    cin >> s;
    for(int i=s.size()-1;i>=0;i--) dfs(string(1,s[i]), i-1, i+1);
    cout << getAns(s);
}