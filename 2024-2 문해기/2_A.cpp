#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <numeric>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 987654321
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000009;


int main() {
    FIO;
    string s; cin >> s;
    cout << (ll)pow(2,(ll)s.size() + 1) - 1;
}