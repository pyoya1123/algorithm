#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <numeric>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 987654321
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000009;


int main() {
    FIO;
    ll tc; cin >> tc;
    while(tc--){
        string s; cin >> s;
        vector<string> tokens;
        size_t pos = 0;
        while(pos < s.size()) {
            pos = s.find("<", pos);
            if(pos == -1) break;
            auto pos2 = s.find(">", pos);
            if(pos2 == string::npos) break;
            string token = s.substr(pos, pos2-pos+1);
            tokens.push_back(token);    
            pos++;
        }
        stack<string> st;
        for(auto e:tokens){
            if(st.empty()) st.push(e);
            else {
                if(e.size() > 1 && e[0] == '<' && e[1] == '/') {
                    st.pop();
                }
                else {
                    st.push(e);
                }
            }
        }
        while(!st.empty()){
            string t = st.top(); st.pop();
            t.insert(t.begin() + 1, '/');
            cout << t;
        }
        cout << "\n";
    }
}