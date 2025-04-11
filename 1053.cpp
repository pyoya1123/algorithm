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
#define MAX 987654321
typedef long long ll;
typedef long double ld;

int dp[55][55]; // dp[i][j] -> i번째부터 r번째까지 팰린드롬일 때의 최솟값 
string s;

int f(int l, int r, string s) {
    if(l >= r) return 0;
    int& ret = dp[l][r];
    if(ret != -1) return ret;
    ret = MAX;
    if(s[l] == s[r]) ret = min(ret, f(l+1, r-1, s)); 
    else ret = min(ret, f(l+1,r-1,s) + 1);
    ret = min(ret, min(f(l+1, r, s) + 1, f(l, r-1, s) + 1));
    return ret;
}

int main() {
    FIO;

    fill(&dp[0][0], &dp[0][0] + 55 * 55, MAX);

    string s; cin >> s;

    int ans = MAX;

    memset(dp, -1, sizeof(dp));
    ans = min(ans, f(0,s.size()-1,s));

    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            memset(dp, -1, sizeof(dp));
            string ss = s;
            swap(ss[i], ss[j]);
            ans = min(ans, f(0,s.size()-1, ss) + 1);
        }
    }

    cout << ans;
}

/*
1,2,3번 연산은 임의로 어떤 연산을 하든간에 팰린드롬이 되는 방향으로 최대한 이득이 되는 연산을 선택할거임
-> 삽입이나 삭제나 어떤 임의의 문자로 교체를 한다고 하더라도 결국 팰린드롬이 되는 방향이니까, 실제 연산을 구현할 필요가 없음.
그냥 l+1 or r-1로만 생각하면 됨. 

*/