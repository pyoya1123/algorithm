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

ll a, b;
vector<ll> ans;

bool isPrime(ll s) {
    if (s <= 1) return false;      // 1 이하의 수는 소수가 아님
    if (s <= 3) return true;       // 2와 3은 소수
    if (s % 2 == 0 || s % 3 == 0)   // 2 또는 3으로 나누어지면 소수가 아님
        return false;

    for (ll i = 5; i * i <= s; i += 6) {
        if (s % i == 0 || s % (i + 2) == 0)
            return false;
    }
    return true;
}

void f(string sum, string m) {
    if(!sum.empty() && sum[0] == '0') return;
    string tmp1 = sum; reverse(tmp1.begin(), tmp1.end());
    string tmp = sum + m + tmp1;
    if(tmp.size() > 0) {
        ll t = stoll(tmp);
        if(t > b) return;
        if(t >= a && isPrime(t)) ans.push_back(t);
    }

    for(ll i=0;i<=9;i++){
        string tmp2 = sum + to_string(i);
        f(tmp2, m);
    }
}

int main() {
    FIO;
    cin >> a >> b;
    f("", "");
    for(ll i=0;i<=9;i++) f("", to_string(i));
    sort(ans.begin(), ans.end());
    for(auto e:ans) cout << e << "\n";
    cout << -1 << "\n";
}