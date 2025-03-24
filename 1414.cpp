// #include <iostream>
// #include <vector>
// #include <string.h>
// #include <set>
// #include <algorithm>
// #include <queue>
// #include <climits>
// using namespace std;

// #define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// typedef long long ll;

// int N;
// string m[55];
// int parent[55];
// bool edge[55][55];
// bool v[55];

// struct node {
//     int a;
//     int b;
//     int cost;
// };

// struct cmp {
//     bool operator()(node a, node b) {
//         return a.cost > b.cost;
//     }
// };

// priority_queue<node, vector<node>, cmp> pq;

// int getValue(char c) {
//     if('a' <= c && c <= 'z') return (c - 'a') + 1;
//     if('A' <= c && c <= 'Z') return (c - 'A') + 27;
//     return 0;
// }

// int find(int x) {
//     if(parent[x] == x) return x;
//     return parent[x] = find(parent[x]);
// }

// bool merge(int a, int b){
//     a = find(a);
//     b = find(b);

//     if(a == b) return false;
//     if(a > b) parent[a] = b;
//     else parent[b] = a;
//     return true;
// } 

// int main() {
//     FIO;
    
//     cin >> N;



//     int sum = 0;

//     for(int i=0;i<=N;i++) parent[i] = i;

//     for(int y=0;y<N;y++) {
//         cin >> m[y];
//         for(int x=0;x<N;x++) {
//             if(m[y][x] != '0') edge[y][x] = edge[x][y] = true;
//             sum += getValue(m[y][x]);
//         }
//     }

//     for(int y=0;y<N;y++) {
//         for(int x=0;x<N;x++){
//             if(y==x) continue;
//             if(m[y][x] == '0') continue;
//             pq.push({y,x,getValue(m[y][x])});
//         }
//     }

//     int ans = 0;

//     while(!pq.empty()){
//         node t = pq.top(); pq.pop();
//         if(merge(t.a, t.b)) {
//             ans += t.cost;
//         }
//     } 

//     int root = find(0);
//     for(int i=1;i<N;i++) {
//         if(find(i) != root) {
//             cout << -1;
//             return 0;
//         }
//     }

//     cout << sum - ans;
// }




//== gpt 최적화 코드 ==//
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 간선 정보를 저장하는 구조체
struct Edge {
    int u, v, cost;
};

// 문자에 따른 케이블 길이 반환 함수
int getValue(char c) {
    if('a' <= c && c <= 'z') return c - 'a' + 1;
    if('A' <= c && c <= 'Z') return c - 'A' + 27;
    return 0;
}

// union-find: find 함수 (경로 압축 적용)
int find(vector<int>& parent, int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent, parent[x]);
}

// union-find: 두 집합을 합치는 함수
bool unionSets(vector<int>& parent, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if(a == b) return false;
    // 단순히 작은 번호를 루트로 지정
    if(a > b) parent[a] = b;
    else parent[b] = a;
    return true;
}

int main() {
    FIO;
    
    int N;
    cin >> N;
    
    vector<string> m(N);
    for (int i = 0; i < N; i++) {
        cin >> m[i];
    }
    
    // 전체 랜선의 총 길이(모든 문자값의 합)
    int total = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            total += getValue(m[i][j]);
        }
    }
    
    // 우선순위 큐(최소 힙)를 사용하여 비용이 작은 간선부터 선택
    auto cmp = [](const Edge &a, const Edge &b) {
        return a.cost > b.cost; // cost가 작은 간선이 우선
    };
    priority_queue<Edge, vector<Edge>, decltype(cmp)> pq(cmp);
    
    // 모든 가능한 간선(자기 자신 제외)을 우선순위 큐에 추가
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (m[i][j] == '0') continue;
            pq.push({i, j, getValue(m[i][j])});
        }
    }
    
    // union-find 초기화 (노드: 0 ~ N-1)
    vector<int> parent(N);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
    
    int mstCost = 0;     // MST에 사용된 랜선 길이의 합
    int edgesUsed = 0;   // 사용한 간선 수
    
    // Kruskal 알고리즘으로 MST 구성
    while(!pq.empty() && edgesUsed < N - 1) {
        Edge e = pq.top();
        pq.pop();
        if (unionSets(parent, e.u, e.v)) {
            mstCost += e.cost;
            edgesUsed++;
        }
    }
    
    // 모든 컴퓨터가 연결되어 있는지 union-find로 확인
    int root = find(parent, 0);
    for (int i = 1; i < N; i++) {
        if(find(parent, i) != root) {
            cout << -1;
            return 0;
        }
    }
    
    // 기부할 수 있는 랜선 길이 = 전체 길이 - MST에 사용한 길이
    cout << total - mstCost;
    
    return 0;
}
