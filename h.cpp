#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 987654321
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000009;

vector<ll> parent;

struct node {
    ll a;
    ll b;
    ll cost;
};

struct cmp {
    bool operator()(const node& a, const node& b) {
        return a.cost > b.cost;
    }
};

ll find(ll x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool merge(ll a, ll b){
    a = find(a);
    b = find(b);
    if(a > b) {
        parent[a] = b;
        return true;
    }
    else if(a < b) {
        parent[b] = a;
        return true;
    }
    else return false;
}

int main() {
    FIO;
    ll tc; cin >> tc;
    while(tc--){
        ll N; cin >> N;
        vector<ll> parent(N+1);
        for(ll i=1;i<=N;i++) parent[i] = i;
        vector<ll> w(N+1);
        for(ll i=1;i<=N;i++) cin >> w[i];
        vector<vector<ll>> graph(N+1, vector<ll>(N+1));

        priority_queue<node, vector<node>, cmp> pq; 

        for(ll y=1;y<=N;y++) {
            for(ll x=1;x<=N;x++) {
                cin >> graph[y][x];
                if(y != x) pq.push({y,x,graph[y][x]});
            }
        }

        ll sum = 0;

        while(!pq.empty()){
            node t = pq.top(); pq.pop();
            if(merge(t.a, t.b)) sum += t.cost;
        }
        
    }
}


/*
2
4
5 4 4 3
0 2 2 2
2 0 3 3
2 3 0 4
2 3 4 0
5
2 17 6 1 35
0 8 4 7 10
8 0 15 15 22
4 15 0 1 35
7 15 1 0 2
10 22 35 2 0

*/


/*
1. 발전소 설치 비용 과 연결된 모든 송전선들의 설치 비용의 최솟값과 비교를 함.
2. 발전소 설치 비용이 더 싸다면 발전소를 설치.
3. 최소 송전선 설치 비용이 더 싸다면 일단 현재는 스킵. 
4. 2번 과정을 모든 정점에 대해서 진행했다면, 해당 정점들을 v로 true 설정 
5. 발전소를 설치하지 않은 정점들에 대해서, 주변 송전선 들을 탐색
6. 탐색하는 과정에서 v가 true인 정점이 존재한다면, 연결
7. 존재하지 않는다면 

*/