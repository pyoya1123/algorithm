#include <iostream>
using namespace std;
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 987654321

int t;
int edge_dis[1005][1005];
int w[1005]; // 발전소 설치 비용 저장 배열 
bool v[1005]; // i 위치에 발전소를 설치했는지 여부 
int parent[1005];
bool vv[1005]; // 발전소 설치 비용이 res값에 추가가 되었는지 여부 

/*
1 
4
2 5 5 2
0 3 10 10
3 0 10 10
10 10 0 3
10 10 3 0
ans: 10

1
4
1 1 1 1
0 10 10 10
10 0 10 10
10 10 0 10
10 10 10 0
ans: 4

*/

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(w[a] > w[b]) parent[a] = b;
    else parent[b] = a; 
    return true;
}

/*
    my sol>
        1. 시설끼리 연결할 때, 내 위치에 발전소 설치 비용보다 작은 간선끼리 합집합 구성 
            ㄴ 이때 부모가 되는 조건은 연구소 설치 비용이 작은 것을 기준으로 구성 
        2. 
*/

int main()
{
    FIO;
    cin >> t;
    while(t--) {
        memset(v,false,sizeof(v));
        memset(vv,false,sizeof(vv));
        int N;
        cin >> N;
        for(int i=1;i<=N;i++) parent[i] = i;
        for(int i=1;i<=N;i++) cin >> w[i];
        for(int y=1;y<=N;y++) for(int x=1;x<=N;x++) cin >> edge_dis[y][x];

        int res = 0;

        for(int i=1;i<=N;i++){
            pair<int,int> tmp = {MAX,MAX};
            for(int j=1;j<=N;j++){
                if(i==j) continue;
                if(edge_dis[i][j] < tmp.second) tmp = {j, edge_dis[i][j]};
            }

            if(w[i] > tmp.second) {
                bool t = merge(i,tmp.first);
                if(t) res += edge_dis[i][tmp.first];
            }
            else {
                v[i] = true;
            }
        }

        for(int i=1;i<=N;i++){
            int p = find(i);
            if(vv[p]) continue;
            vv[p] = true;
            res += w[p];
        }

        cout << res << "\n";
    }
}