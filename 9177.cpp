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

int tc;
int dp[444][444]; // a를 선택한 번째 수, b를 선택한 번째 수 
string a,b,c;
int ans = -1;

int dfs(int p_a, int p_b, string sum, int cnt, int c_a, int c_b) {
    // cout << p_a << ", " << p_b << ", " <<  sum << ", " << cnt << ", " << c_a << ", " << c_b << "!\n";
    if(p_a > a.size()-1 || p_b > b.size()-1) return -1; 
    
    int& ret = dp[c_a][c_b];
    if(ret != 0) return ret;
    
    if(p_a > 0 || p_b > 0){
        if(sum.compare(c) == 0) {
            ans = 1;
        }
        if(sum.compare(c.substr(0,sum.size())) != 0) return ret = -1;
    }
    if(p_a < a.size()) ret = min(ret, dfs(p_a+1, p_b, sum + a[p_a+1], cnt+1, cnt+1, c_b));
    if(p_b < b.size()) ret = min(ret, dfs(p_a, p_b+1, sum + b[p_b+1], cnt+1, c_a, cnt+1));

    return ret;
}

int main() {
    FIO;

    cin >> tc;
    for(int i=1;i<=tc;i++){
        ans = -1;
        cin >> a >> b >> c;
        memset(dp, 0, sizeof(dp));
        a = "-" + a, b = "-" + b;
        dfs(0,0,"",0,0,0);
        cout << "Data set " << i << ": " << (ans == 1 ? "yes\n" : "no\n");
    }
}