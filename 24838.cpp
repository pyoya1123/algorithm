#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 987654321
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;

int main() {
    FIO;

    vector<ll> fac(50005);
    fac[0] = 1;
    for(ll i=1;i<=50000;i++){
        fac[i] = (fac[i-1] * i) % MOD;
    }

    ll tc; cin >> tc;
    while(tc--){
        ll n,m; cin >> n >> m;
        vector<ll> vec(n);
        vector<ll> dp(n+2);
        vector<ll> freq(n);
        for(ll i=0;i<n;i++) cin >> vec[i];
        for(ll i=0;i<m;i++){
            ll l,r; cin >> l >> r;
            dp[l-1]++,dp[r]--;
        }
        ll cur = 0;
        for(ll i=0;i<n;i++) {
            cur += dp[i];
            freq[i] += cur;
        }
        sort(vec.begin(), vec.end());
        sort(freq.begin(), freq.end());
        ll sum = 0;
        for(ll i=0;i<n;i++) sum += vec[i] * freq[i];

        vector<ll> cnt2(m+1);
        for(auto e:freq) cnt2[e]++;
        
        ll cnt = 1;
        for(auto e:cnt2) cnt = (cnt * fac[e]) % MOD;
        cout << sum << " " << cnt << "\n";
    }
}

/*
죄송합니다, 설명에 착오가 있었습니다. $\texttt{diff[4]}$ 값은 $-2$가 아니라 $-1$이 맞습니다. 올바른 과정을 다시 정리해 드릴게요.

---

### 예제 복습

* $N=5$, 쿼리 $(1,3),(2,5),(3,4)$

#### 1) 초기 `diff` (크기 $N+2=7$, 1번부터 6번만 사용)

```
index:   1  2  3  4  5  6
diff  = [0, 0, 0, 0, 0, 0]
```

#### 2) 각 쿼리 반영

1. 쿼리 (1,3):

   ```
   diff[1] += 1 → diff[1]=1
   diff[3+1] -= 1 → diff[4]=-1
   ```

   → `[1, 0, 0, -1, 0, 0]`

2. 쿼리 (2,5):

   ```
   diff[2] += 1 → diff[2]=1
   diff[5+1] -= 1 → diff[6]=-1
   ```

   → `[1, 1, 0, -1, 0, -1]`

3. 쿼리 (3,4):

   ```
   diff[3] += 1 → diff[3]=1
   diff[4+1] -= 1 → diff[5]=-1
   ```

   → `[1, 1, 1, -1, -1, -1]`

여기서 $\texttt{diff[4]}$ 는 $-1$ 하나만 찍혔기 때문에 $-2$가 아니라 $-1$입니다.

#### 3) 누적합으로 `freq` 계산

```cpp
cur = 0;
for i in 1..5:
    cur += diff[i];
    freq[i] = cur;
```

|  i  | diff\[i] | cur 전 단계 | cur 후 (+=diff\[i]) | freq\[i] |
| :-: | :------: | :------: | :----------------: | :------: |
|  1  |     1    |     0    |          1         |     1    |
|  2  |     1    |     1    |          2         |     2    |
|  3  |     1    |     2    |          3         |     3    |
|  4  |    −1    |     3    |          2         |     2    |
|  5  |    −1    |     2    |          1         |     1    |

최종적으로

$$
\text{freq} = [1,\,2,\,3,\,2,\,1]
$$

*/