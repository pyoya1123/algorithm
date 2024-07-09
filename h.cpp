#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 987654321
#define mod 1000000009

long long dp[1000005];

int main()
{
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i = 4; i <= 1000000; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
}

/*
    입력되는 숫자에 대해 1,2,3으로 구성되어있는 조합들의 패턴을 파악하면 풀기 쉽다.
    1 2 3 이라는 제한된 조건이 있기 때문에
    4라고 예를 들면,
    1로 구성된 조합에서 3을 더하고,
    2으로 구성된 조합에서 2를 더하고,
    3으로 구성된 조합에서 1을 더하면
    4로 구성된 조합을 얻을 수 있다.
    따라서 점화식은 dp[i-1] + dp[i-2] + dp[i-3] 이 되며, 모드값으로 모듈러 연산을 해주면 된다.
*/