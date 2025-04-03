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

int tc;
vector<string> ans;

/*손에서 뼈가 나온 곳이 31, 들어간 곳이 30*/
int arr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int arr2[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

bool isYun(int y) {
    if(((y % 4 == 0) && (y % 100 != 0)) || ((y % 4 == 0) && (y % 100 == 0) && (y % 400 == 0))) return true;
    return false;
}

int calc(int y, int m, int d){
    int res = 365 + isYun(y);
    for(int i=12;i>=m;i--) {
        if(isYun(y)) res -= arr2[i];
        else res -= arr[i];
    }
    res += d;
    return res;
}

int main() {
    FIO;
    cin >> tc;
    cin.ignore();
    /*
    cin >> tc; 는 입력 스트림에서 공백 문자(여기서는 공백, 탭, 개행 문자 등)를 구분자로 사용하여 데이터를 읽음.
    그래서 7 을 입력받고 엔터가 쳐지면 7\n가 들어가는데, 연산자는 숫자 7을 읽고, 그 뒤에 있는 개해 문자(\n)는 숫자 읽기 작업의
    일부로 사용되었지만 실제로 스트림에서 제거되지 않고 남게됨.
    getline(cin, s)를 호출할 때 문제가 발생함. getline은 입력 스트림에서 한 줄 전체를 읽는데, 첫번째 호출에서는 스트림에 
    남아있는 개행문자(\n)를 만나자마자 빈 문자열을 읽어들이게 됨. 따라서 실제 데이터가 담긴 첫번째 줄
    11/20/2005 11/21 는 건너뛰게 되는거임.
    */

    /*
    4로 나누어 떨어지고,
    100으로 나누어 떨어지지만,
    400으로 안나누어 떨어지면 평년 

    4로 나누어 떨어지고,
    100으로 나누어 떨어지나,
    400으로 나누어 떨어지면 윤년 
    */
    while(tc--){
        string s;
        getline(cin, s);

        vector<string> tokens;
        istringstream iss(s);
        string token;
        while(getline(iss, token, ' ')) {if(!token.empty()) tokens.push_back(token);}

        // 첫번쨰 문장 / 단위로 파싱
        vector<string> tokens1;
        istringstream iss1(tokens[0]);
        while(getline(iss1, token, '/')) {if(!token.empty()) tokens1.push_back(token);}

        // 두번째 문장 / 단위로 파싱
        vector<string> tokens2;
        istringstream iss2(tokens[1]);
        while(getline(iss2, token, '/')) {if(!token.empty()) tokens2.push_back(token);}

        int y1 = stoi(tokens1[2]);
        int y2 = y1;
        int sum = 365;
        if(isYun(y1)) sum = 366;

        int m1 = stoi(tokens1[0]);
        int m2 = stoi(tokens2[0]);
        
        int d1 = stoi(tokens1[1]);
        int d2 = stoi(tokens2[1]);

        int t1 = calc(y1,m1,d1);
        int t2 = calc(y2,m2,d2);

        int sub = t1 - t2;
        if(sub > 300) { // 보고서 제출 마감일이 2005년 12월쯤이고, 현재 제출일이 1월쯤임. 그니까 현재는 2006년임
            y2 = y1+1;
            sub = t1 - (calc(y2,m2,d2) + (isYun(y1) ? 366 : 365));
        }
        else if(sub < -300){ // 보고서 제출 마감일이 2005년 1월 쯤이고, 현재 제출일이 12월쯤임. 그니까 현재는 2004년임
            y2 = y1-1;
            sub = (t1 + (isYun(y2) ? 366 : 365)) - calc(y2,m2,d2); 
        }

        if(0 < sub && sub <= 7) {
            ans.push_back(to_string(m2) + "/" + to_string(d2) + "/" + to_string(y2) + " IS " 
            + to_string(abs(sub)) + (abs(sub) == 1 ? " DAY" : " DAYS") + " PRIOR");
        }
        else if(-7 <= sub && sub < 0) {
            ans.push_back(to_string(m2) + "/" + to_string(d2) + "/" + to_string(y2) + " IS " 
            + to_string(abs(sub)) + (abs(sub) == 1 ? " DAY" : " DAYS") + " AFTER");
        }
        else if(sub == 0){
            ans.push_back("SAME DAY");
        }
        else {
            ans.push_back("OUT OF RANGE");
        }
    }

    for(auto e:ans) cout << e << "\n";
}