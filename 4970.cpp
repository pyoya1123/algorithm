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

vector<int> temp; // 0 -> P, 1 -> Q, 2 -> R
vector<vector<int>> vec;
const int MINUS = 987654321;
const int PLUS = 987654322;
const int MULTIPLY = 987654323;
const int PAR_LEFT = 987654324;
const int PAR_RIGHT = 987654325;

void b(int cnt) {
    if(cnt >= 3){
        vec.push_back(temp);
        return;
    }
    for(int i=0;i<=2;i++){
        temp.push_back(i);
        b(cnt+1);
        temp.pop_back();
    }
}

int calc_not(int a) {
    if(a == 0) return 2;
    else if(a == 2) return 0;
    else return 1;
}

int calc_and(int a, int b) {
    if(a == 0 || b == 0) return 0;
    if(a == 1 || b == 1) return 1;
    return 2;
}

int calc_or(int a, int b) {
    if(a == 0 && b == 0) return 0;
    if((a != 2 && b != 2) && (a == 1 || b == 1)) return 1;
    return 2;
}

int calc(int a, int oper, int b) {
    if(oper == PLUS) return calc_or(a,b);
    else return calc_and(a,b);
}

void f(string s) {
    int res = 0;
    for(auto al:vec){
        stack<int> st;
        for(auto e:s){
            if(e == '(') st.push(PAR_LEFT);
            if(e == ')'){
                int s = st.top(); st.pop();
                int oper = st.top(); st.pop();
                int f = st.top(); st.pop();
                int ee = calc(f,oper,s);

                // 남아있는 ( 도 제거
                if(!st.empty() && st.top() == PAR_LEFT) st.pop();
                while(!st.empty() && st.top() == MINUS){
                    st.pop();
                    ee = calc_not(ee);
                }
                st.push(ee);
            }
            if(e == '-') st.push(MINUS);
            if(e == 'P' || e == 'Q' || e == 'R' || isdigit(e)){
                int ee = (isdigit(e) ? e - '0' : al[(int)e-80]);
                while(!st.empty() && st.top() == MINUS){
                    st.pop();
                    ee = calc_not(ee);
                }
                st.push(ee);
            }
            if(e == '+' || e == '*') {
                if(e == '*') st.push(MULTIPLY);
                else st.push(PLUS);
            }
        }
        if(st.top() == 2) res++;
    }
    cout << res << "\n";
}

int main() {
    FIO;
    b(0);
    string s;
    while(cin >> s && s != ".") {
        f(s);
    }
}


/*

() 앞에 -가 있는 경우의 수도 고려하자.
*/