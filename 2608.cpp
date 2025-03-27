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

struct token {
    string s;
    int v;
};

vector<token> vec = {
    {"MMM",3000},{"MM",2000},{"M",1000},
    {"CM",900},{"DCCC",800},{"DCC",700},{"DC",600},{"D",500},{"CD",400},{"CCC",300},{"CC",200},{"C",100},
    {"XC",90},{"LXXX",80},{"LXX",70},{"LX",60},{"L",50},{"XL",40},{"XXX",30},{"XX",20},{"X",10},
    {"IX",9},{"VIII",8},{"VII",7},{"VI",6},{"V",5},{"IV",4},{"III",3},{"II",2},{"I",1}
};

bool isMatching(string s, token e) {
    for(int i=0;i<e.s.size();i++){
        if(i >= s.size()) return false;
        if(e.s[i] != s[i]) return false;
    }
    return true;
}

int getIntValue(const string &s) {
    int res = 0;
    size_t pos = 0;
    while (pos < s.size()) {
        for (const auto &e : vec) {
            if (pos + e.s.size() <= s.size() && s.compare(pos, e.s.size(), e.s) == 0) {
                res += e.v;
                pos += e.s.size();  
                break;  
            }
        }
    }
    return res;
}


string findString(int v) {
    for(int i=0;i<vec.size();i++){
        if(vec[i].v == v) return vec[i].s;
    }
    return "";
}

string getStringValue(int v) {
    string res = "";
    int cnt = 0;
    while(v){
        int tmp = v % 10;
        v /= 10;
        string fs = findString(tmp * pow(10, cnt));
        res = fs + res;
        cnt++;
    }
    return res;
}

int main() {
    FIO;
    
    string f,s;
    cin >> f >> s;
    int sum = getIntValue(f) + getIntValue(s);
    cout << sum << "\n";
    cout << getStringValue(sum) << "\n";
}


/*

`std::string::compare`는 C++ 표준 라이브러리에서 제공하는 문자열 비교 함수입니다. 이 함수는 두 문자열(또는 문자열의 일부)을 사전식으로 비교하여, 그 결과를 정수 값으로 반환합니다. 위의 코드에서 사용한 형태는 다음과 같습니다:

```cpp
s.compare(pos, len, e.s)
```

이 표현의 의미를 자세히 설명하면:

- **s:** 비교 대상이 되는 원본 문자열입니다.
- **pos:** 원본 문자열 `s`에서 비교를 시작할 인덱스입니다.
- **len:** 비교할 문자 개수입니다. 즉, `s`의 `pos`부터 `len`개의 문자를 추출합니다.
- **e.s:** 비교할 대상 문자열입니다. 이 문자열과 `s`의 부분 문자열을 비교합니다.

함수의 반환값은 다음과 같이 해석됩니다:
- **0:** 두 문자열이 정확히 동일함을 의미합니다.
- **음수:** `s.substr(pos, len)`가 `e.s`보다 사전식으로 작음을 의미합니다.
- **양수:** `s.substr(pos, len)`가 `e.s`보다 사전식으로 큼을 의미합니다.

위의 최적화된 `getIntValue` 함수에서는 다음과 같이 사용되었습니다:

```cpp
if (pos + e.s.size() <= s.size() && s.compare(pos, e.s.size(), e.s) == 0) {
    res += e.v;
    pos += e.s.size();
    matched = true;
    break;
}
```

여기서 `s.compare(pos, e.s.size(), e.s) == 0`는 현재 문자열 `s`의 `pos` 위치부터 `e.s.size()` 길이만큼 추출한 부분 문자열이, 토큰의 로마 숫자 표현 `e.s`와 정확히 일치하는지를 확인하는 역할을 합니다.

이 함수를 사용하면 내부적으로 반복문이나 수동 비교 없이, 최적화된 방식으로 문자열의 일부분을 빠르게 비교할 수 있으므로, 성능과 코드 가독성 측면에서 매우 유용합니다.
*/