#include <iostream>
using namespace std;
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 987654321

int n;

char arr[3] = {'4', '5', '6'};

string ans = "-1";

bool check(int sz, string s, int l){
    if(sz == 1) return true;
    int p=0,q=l;
    while(q <= sz-l){
        string left = s.substr(p,l);
        string right = s.substr(q,l);
        if(left.compare(right) == 0) return false;
        p++, q++;
    }
    return true;
}

bool isFinish = false;

void f(int idx, string s) {
    if(isFinish) return;
    if(idx == n) {
        ans = s;
        isFinish = true;
        return;
    }

    
     for(int i=0;i<3;i++){
        bool canPush = true;
        s[idx] = arr[i];
        for(int l=1;l<=(idx+1)/2;l++){
            if(!check(idx+1, s, l)){
                canPush = false;
                break;
            }
        }
        if(canPush) {
            f(idx + 1, s);
        }
     }
}

int main()
{
    FIO;
    string s;

    cin >> n;
    s.resize(n);
    f(0, s);
    cout << ans << "\n";
}