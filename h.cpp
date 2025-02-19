#include <iostream>
#include <vector>

using namespace std;

int N;
int s[1005], e[1005], p[1005];
int dp[1005];

class node {
    public:
        int s;
        int e;
        int p;
        node() {}
        node(int s, int e, int p):s(s), e(e), p(p) {}
};

vector<node> vec;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i] >> p[i];
        vec.push_back(node(s[i], e[i], p[i]));
    }

    for(int i=0;i<N;i++){
        dp[i] = p[i];
        for(int j=0;j<i;j++){
            if(vec[j].e >= vec[i].s) continue;
            dp[i] = max(dp[j] + p[i], dp[i]);
        }
    }

    int ans = 0;
    for(int i=0;i<N;i++) ans = max(ans, dp[i]);
    cout << ans;

    return 0;
}
