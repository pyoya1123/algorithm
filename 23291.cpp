#include <iostream>
#include <deque>
#include <vector>
#include <climits>
#include <queue>
#include <string.h>

using namespace std;
typedef long long ll;

int N,K;
deque<int> m[105];
bool v[105][105];
int dir_y[4] = {-1,1,0,0};
int dir_x[4] = {0,0,-1,1};

void _copy(deque<int> new_m[105]) {
    for(int y=0;y<105;y++) m[y] = new_m[y];
}

void print_map(int current_height) {
    deque<int> temp[105];
    for(int y=0;y<105;y++) temp[y] = m[y];
    for(int h=100-current_height+1;h<=100;h++) {
        while(!temp[h].empty()){
            cout << temp[h].front() << " "; temp[h].pop_front();
        }
        cout << "\n";
    }
    cout << "\n";
}

int find_min(deque<int> mm) {
    int res = INT_MAX;
    while(!mm.empty()){
        res = min(mm.front(), res);
        mm.pop_front();
    }
    return res;
}

deque<int> get_plus_min_idx(deque<int> mm, int min_value) {
    deque<int> res;
    while(!mm.empty()){
        int t = mm.front(); mm.pop_front();
        if(t == min_value) res.push_back(t + 1);
        else res.push_back(t);
    }
    return res;
}

void raise(int current_height, int current_width) {   
    if(m[100].size() - current_width < current_height) return;

    deque<int> new_m[105];
    int w = current_width;
    int h = 100 - current_height;
    while(w--){
        int ww = w+1;
        for(int hh=100-current_height+1;hh<=100;hh++){
            new_m[100 - ww].push_front(m[hh].front());
            m[hh].pop_front();    
        }
        ww--;
    }
    while(!m[100].empty()){
        new_m[100].push_back(m[100].front());
        m[100].pop_front();
    }
    _copy(new_m);
    
    if(current_height == current_width) raise(current_height+1, current_width);
    else raise(current_height, current_width+1);
}

void raise_180() {
    deque<int> new_m[105];
    deque<int> f1;
    int w = m[100].size() / 2;
    while(w--){
        f1.push_front(m[100].front());
        m[100].pop_front();
    }

    w = m[100].size() / 2;
    for(int i=0;i<w;i++){
        new_m[97].push_front(m[100].front());
        m[100].pop_front();
    }
    for(int i=0;i<w;i++){
        new_m[98].push_front(f1.front());
        f1.pop_front();
    }
    while(!f1.empty()){
        new_m[99].push_back(f1.front());
        f1.pop_front();
    }
    while(!m[100].empty()){
        new_m[100].push_back(m[100].front());
        m[100].pop_front();
    }
    _copy(new_m);
}

vector<vector<int> > copy_to_vector() {
    vector<vector<int> > res(105, vector<int>(105, 0));
    deque<int> temp[105];
    for(int y=0;y<105;y++) temp[y] = m[y];
    for(int y=0;y<105;y++){
        while(!temp[y].empty()){
            res[y][temp[y].size()-1] = temp[y].back();
            temp[y].pop_back();
        }
    }
    return res;
}

void _arrange() {
    vector<vector<int> > _map = copy_to_vector();
    vector<vector<int> > cnt(105, vector<int>(105,0));

    memset(v, false, sizeof(v));

    queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    while(!q.empty()){
        pair<int,int> t = q.front(); q.pop();
        if(v[t.first][t.second]) continue;
        v[t.first][t.second] = true;
        for(int dir=0;dir<4;dir++){
            int dy = t.first + dir_y[dir];
            int dx = t.second + dir_x[dir];
            if(dy > 100 || dy < 0 || dx > 100 || dx < 0) continue;
            if(v[dy][dx]) continue;
            q.push(make_pair(dy,dx));
            int cur = _map[t.first][t.second];
            int next = _map[dy][dx];
            if(cur == 0 || next == 0) continue;
            if(next - cur >= 5){
                cnt[dy][dx] -= (next - cur) / 5;
                cnt[t.first][t.second] += (next - cur) / 5;
            }
            if(cur - next >= 5) {
                cnt[dy][dx] += (cur - next) / 5;
                cnt[t.first][t.second] -= (cur - next) / 5;
            }
        }
    }

    deque<int> temp[105];
    for(int y=0;y<105;y++){
        int x = 0;
        while(!m[y].empty()){
            int t = m[y].front(); m[y].pop_front();
            temp[y].push_back(t + cnt[y][x]);
            x++;
        }
    }
    _copy(temp);
}

void spread() {
    deque<int> temp[105];
    int l = m[100].size();
    while(l--){
        int y = 100;
        while(y) {
            if(!m[y].empty()) {
                temp[100].push_back(m[y].front());
                m[y].pop_front();
            }
            else break;
            y--;
        }
    }
    _copy(temp);
}

int get_sub_fish_cnt() {    
    int _max = -1, _min = 100005;

    deque<int> temp = m[100];

    while(!temp.empty()){
        int t = temp.front();
        _max = max(_max, t);
        _min = min(_min, t);
        temp.pop_front();
    }
    return _max - _min;
}

int main() {
    cin >> N >> K;
    for(int i=0;i<N;i++){
        int input; cin >> input;
        m[100].push_back(input);
    }

    int ans = 0;

    int t = get_sub_fish_cnt();

    while(t > K) {
        int min_value = find_min(m[100]);
        m[100] = get_plus_min_idx(m[100], min_value);
        raise(1, 1);
        _arrange();
        spread();
        raise_180();
        _arrange();
        spread();
        ans++;
        t = get_sub_fish_cnt();
    }

    cout << ans << "\n";

    return 0;
}
