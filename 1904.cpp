#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 987654321
#define mod 15746

long long dp[1000005];

int N;

int main()
{
    dp[1] = 1, dp[2] = 2, dp[3] = 3;
    for (int i = 4; i <= 1000000; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    cin >> N;
    cout << dp[N] << "\n";
}

/*
    3:
100
001
111

4:
0011
0000
1001
1100
1111

5:
10000
00100
11100
-> 3의 경우의 수들에서 00을 붙인 경우

00111
00001
10011
11001
11111
-> 4의 경우의 수들에서 1을 붙인 경우

--> 점화식은 dp[i] = dp[i-1] + dp[i-2]
*/