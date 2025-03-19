#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

class node {
    public:
        int idx;
        int next_node;
        int _time;
        node() {}
        node(int idx, int next_node, int _time):idx(idx), next_node(next_node), _time(_time){}
};

int N,M;
int srt, _end;
vector<node> graph[10005];
vector<node> graph_reverse[10005];

int dp[10005];
set<int> s;
bool v[100005];

void bfs() {
    queue<pair<int, int> > q;
    q.push(make_pair(srt, 0));
    while(!q.empty()){
        pair<int,int> t = q.front(); q.pop(); // node_num, sum
        for(int i=0;i<graph[t.first].size();i++){
            int e = graph[t.first][i].next_node;
            int _time = graph[t.first][i]._time;
            if(dp[e] >= t.second + _time) continue;
            dp[e] = t.second + _time;
            q.push(make_pair(e, dp[e]));
        }
    }
}

void bfs_reverse() {
    queue<pair<int,int> > q;
    q.push(make_pair(_end, dp[_end]));
    while(!q.empty()){
        pair<int,int> t = q.front(); q.pop();
        for(int i=0;i<graph_reverse[t.first].size();i++){
            int e = graph_reverse[t.first][i].next_node;
            int _time = graph_reverse[t.first][i]._time;
            int idx = graph_reverse[t.first][i].idx;
            if(dp[e] != t.second - _time) continue;
            if(v[idx]) continue;
            v[idx] = true;
            s.insert(graph_reverse[t.first][i].idx);
            q.push(make_pair(e, t.second - _time));
        }
    }
}

int main() {
    FIO;

    cin >> N >> M;
    for(int i=0;i<M;i++){
        int src, dst, _time;
        cin >> src >> dst >> _time;
        graph[src].push_back(node(i, dst, _time));
        graph_reverse[dst].push_back(node(i, src, _time));
    }
    cin >> srt >> _end;
    dp[srt] = 0;

    bfs();
    bfs_reverse();

    cout << dp[_end] << "\n" << s.size() << "\n";
}



/*

tip > 
역추적할 때 주의해야함.
정점 a, b가 있고, 이 둘을 잇는 간선 z가 있다고 하자. 
b,c,d,e에서 각각 a를 탐색하고, b로 가는 경우가 있을 때,
간선 z를 지나는건 똑같음. 이거를 방문처리 해서 중복으로 탐색하는 경우를 배제해주자.

*/