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

string pattern;
int n;
vector<string> vec;
bool dp[105]; // dp[i] -> i번째까지 매칭이 됨.
int ans = 0;

bool exist(string s){
    for(auto e:vec) if(s.compare(e) == 0) return true;
    return false;
}

int main() {
    FIO;

    cin >> pattern;
    pattern = " " + pattern;
    cin >> n;
    vec.resize(n);
    for(int i=0;i<n;i++) cin >> vec[i];

    dp[0] = true;
    for(int i=1;i<pattern.size();i++){
        for(int j=1;j<=i;j++){
            string str = pattern.substr(j,(i-j+1));
            if(dp[j-1] && exist(str)) dp[i] = true;
        }
    }
    cout << dp[pattern.size()-1];
}