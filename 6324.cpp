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

pair<string,string> splitByDelimiter(const string &str, const string& delimiter) {
    size_t start = 0, pos = 0;
    if((pos = str.find(delimiter, 0)) != string::npos){
        return {str.substr(0, pos), str.substr(pos + delimiter.length())};
    }
    return {"", str};
}

int main() {
    FIO;
    
    cin >> n;
    for(int i=1;i<=n;i++){
        cout << "URL #" << i << "\n";
        string s; cin >> s;
        pair<string, string> tmp = splitByDelimiter(s, "://");
        string protocol = tmp.first;
        s = tmp.second;
        cout << "Protocol = " << protocol << "\n";

        tmp = splitByDelimiter(s, ":");
        cout << "Host     = ";
        if(tmp.first == "" || !isdigit(tmp.second[0])) { // port가 없을 때 
            tmp = splitByDelimiter(s, "/");
            if(tmp.first == "") { // path가 없을 때 
                cout << tmp.second << "\n";
                cout << "Port     = <default>\n";
                cout << "Path     = <default>\n";
            }   
            else {
                cout << tmp.first << "\n";
                cout << "Port     = <default>\n";
                cout << "Path     = " << tmp.second << "\n";
            }
        }
        else { // port가 있을 때 
            cout << tmp.first << "\n";
            cout << "Port     = ";
            s = tmp.second;
            tmp = splitByDelimiter(s, "/");
            if(tmp.first == ""){ // path가 없을 때  
                cout << tmp.second << "\n";
                cout << "Path     = <default>\n";
            }
            else {
                cout << tmp.first << "\n";
                cout << "Path     = " << tmp.second << "\n";
            }
        }
        cout << "\n";
    }
}


/*
1
http://www.acmicpc.net/abc://def
*/