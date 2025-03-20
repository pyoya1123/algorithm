#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// true면 a 
bool check(string a, string b) {
    int p_a = 0, p_b = 0;
    int sz_a = (int)a.size(), sz_b = (int)b.size();
    int sz = sz_a + sz_b;
    int idx = 0;
    while(idx < sz) {
        p_a %= sz_a;
        p_b %= sz_b;
        if(a[p_a] < b[p_b]) return false;
        else if(a[p_a] > b[p_b]) return true;
        p_a++, p_b++;
        idx++;
    }
    return true;
}

struct cmp {
    bool operator()(string a, string b) {
        return !check(a,b);
    }
};

int N;
vector<string> vec;
priority_queue<string, vector<string>, cmp> pq;

int main() {
    FIO;

    cin >> N;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        pq.push(s);
    }

    if(!pq.empty()){
        while(pq.size() > 1 && pq.top() == "0"){pq.pop();}
    }
    
    while(!pq.empty()){
        cout << pq.top(); pq.pop();
    }
    cout << "\n";
}


/*
2
21421 214
ans : 21421421
*/