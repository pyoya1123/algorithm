#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
#include <cctype>
#include <stack>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <deque>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;

int n;
vector<string> vec;
unordered_map<string, int> um;

bool compare(string a, string b){return a.size() > b.size();}

bool check1(string bound, string input, char type) {
    if(type == 'P'){
        for(int i=0;i<input.size();i++){
            if(bound[i] != '\0' && bound[i] != ' ' && bound[i] != input[i]) return false;
        }
    }
    else {
        for(int i=bound.size()-1,j=input.size()-1;i>=0 && j>=0;i--,j--){
            if(bound[i] != '\0' && bound[i] != ' ' && bound[i] != input[j]) return false;
        }
    }
    return true;
}

bool check(string bound, string p, string s) {
    bound.replace(0, p.size(),p);
    int j=s.size()-1;
    for(int i=bound.size()-1;i>=0 && j>=0;i--,j--) if(bound[i] != '\0' && bound[i] != ' ' && bound[i] != s[j]) return false;
    for(int sz=p.size()-1;sz>=1;sz--){
        bool t = false;
        for(auto e:vec) {
            if(e.size() == sz) {
                if(check1(p, e, 'P')) {
                    t = true;
                    break;
                }
            }
        }
        if(!t) return false;
    }
    for(int sz=s.size()-1;sz>=1;sz--){
        bool t = false;
        for(auto e:vec) {
            if(e.size() == sz) {
                if(check1(s, e, 'S')) {
                    t = true;
                    break;
                }
            }
        }
        if(!t) return false;
    }
    return true;
}



int main() {
    FIO;
    
    cin >> n;
    for(int i=0;i<2*n-2;i++){
        string s; cin >> s; vec.push_back(s);
    }
    vector<string> temp = vec;
    sort(temp.begin(), temp.end(), compare);

    string p = temp[0];
    string s = temp[1];

    if(!check(string(n, ' '), p, s)) swap(p,s);
    string bound = string(n, ' ');
    bound.replace(0, p.size(), p);
    bound.replace(bound.size() - s.size(), s.size(), s);
    // cout << p << ", " << s << "!\n";

    cout << bound << "\n";
    for(auto e:vec) {
        if(check1(p,e,'P')){
            auto it = um.find(e);
            if(it == um.end()){
                um.insert({e, 1});
                cout << 'P';
            }
            else cout << 'S';
        }
        else {
            cout << 'S';
        }
    }

}