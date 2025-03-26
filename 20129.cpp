#include <iostream>
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
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;

enum TokenType {
    NUMBER,
    OPERATOR
};

struct Token {
    TokenType type;
    string value;
};

int p[4]; // + - * /
string arr[4] = {"+", "-", "*", "/"};
string s;

vector<Token> tokenizeFromRight(const string& expr) {
    vector<Token> tokens;
    int i = expr.size() - 1;

    while(i >= 0){
        // 만약 연산자라면 토큰으로 추가
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/'){
            tokens.push_back({OPERATOR, string(1, expr[i])});
            i--;
        }
        // 숫자인 경우 연속된 숫자를 하나의 토큰으로 추출
        else if(isdigit(expr[i])) {
            int end = i;
            // 뒤에서부터 연속된 숫자들을 스캔 (i가 숫자가 아니게 될 때까지)
            while(i>=0 && isdigit(expr[i])){
                i--;
            }
            // i+1부터 end까지가 숫자 부분 (원래 순서 그대로)
            string numStr = expr.substr(i + 1, end - i);

            int pos = 0;
            while(pos < numStr.size() && numStr[pos] == '0') {
                pos++;
            }
            if(pos == numStr.size()) {
                numStr = "0";
            } else {
                numStr = numStr.substr(pos);
            }
            tokens.push_back({NUMBER, numStr});
        }
        // 숫자나 연ㅅ나자가 아닌 경우 무시 
        else {
            i--;
        }
    }

    reverse(tokens.begin(), tokens.end());
    return tokens;
}

string calc(string f, string s, string oper) {
    if(oper == "+") return to_string(stoll(f) + stoll(s));
    if(oper == "-") return to_string(stoll(f) - stoll(s));
    if(oper == "*") return to_string(stoll(f) * stoll(s));
    if(oper == "/") return to_string(stoll(f) / stoll(s));
    return "";
}

int findValue(int value) {
    for(int i=0;i<4;i++) if(value == p[i]) return i;
    return 0;
}

int main() {
    FIO;
    
    for(int i=0;i<4;i++) cin >> p[i];
    cin >> s;

    vector<Token> tokens = tokenizeFromRight(s);

    stack<Token> st;
    for(auto e:tokens) st.push(e);

    string ans = "";
    stack<Token> temp_stack;

    for(int i=4;i>=1;i--){
        while(!temp_stack.empty()){
            st.push(temp_stack.top()); 
            temp_stack.pop();
        }
        string c = arr[findValue(i)];
        while(!st.empty()){
            Token f = st.top(); st.pop();
            if(st.empty()) {
                ans = f.value;
                temp_stack.push(f);
                break;
            }
            Token oper = st.top(); st.pop();
            if(st.empty()){
                break;
            }
            Token s = st.top(); st.pop();
            if(oper.value == c) {
                string res = calc(f.value,s.value,oper.value);
                st.push({NUMBER, res});
            }
            else {
                temp_stack.push(f);
                temp_stack.push(oper);
                st.push(s);
            }
        }
    }

    cout << ans;

}