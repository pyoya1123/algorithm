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
typedef long double ld;


int main() {
    FIO;

    ll tc; cin >> tc;
    while(tc--){
        unordered_map<string, ll> types;
        ll n,b; cin >> n >> b;
        cin.ignore();
        vector<vector<string>> arr;
        for(ll i=0;i<n;i++){
            string s; getline(cin, s);
            istringstream iss(s);
            string token;
            vector<string> tokens;
            while(getline(iss, token, ' ')) if(!token.empty()) tokens.push_back(token); 
            arr.push_back(tokens);
            auto it = types.find(tokens[0]);
            if(it == types.end()) types.insert({tokens[0], 1});
        }

        ll ans = 0;
        ll l = 0, r = 1000000000;
        while(l <= r){
            unordered_map<string, ll> um;
            ll bb = b;
            ll mid = (l+r)/2;
            for(auto e:arr) {
                string type = e[0];
                ll cost = stoll(e[2]);
                ll quality = stoll(e[3]);
                auto it = um.find(type);
                if(it != um.end()){
                    if(quality >= mid) {
                        if((*it).second > cost) {
                            ll sub = (*it).second - cost;
                            bb += sub;
                            (*it).second = cost;
                        }
                    }
                } else {
                    // 남아 있는 예산으로 부품을 구매할 수 있는지 
                    if(quality >= mid) {
                        if(cost <= bb){
                            um.insert({type, cost});
                            bb -= cost;
                        }
                    }
                }
            }

            bool allIncludeTypes = true;
            for(auto e:types){
                auto it = um.find(e.first); 
                if(it == um.end()) {allIncludeTypes = false; break;}
            }
            if(allIncludeTypes){
                l = mid + 1;
                ans = max(ans, mid);
            }
            else r = mid - 1;
        }
        cout << ans << "\n";
    }
}


/*
type name price quality

1
18 1000000000
processor 3500_MHz 125000000 5
processor 4200_MHz 125000000 7
processor 5000_MHz 125000000 9
processor 6000_MHz 125000000 12
memory 1_GB 125000000 3
memory 2_GB 125000000 6
memory 4_GB 125000000 12
mainbord all_onboard 125000000 10
harddisk 250_GB 125000000 10
harddisk 500_FB 125000000 12
casing midi 125000000 10
monitor 17_inch 125000000 5
monitor 19_inch 125000000 7
monitor 20_inch 125000000 9
monitor 22_inch 125000000 12
mouse cordless_optical 125000000 12
mouse microsoft 125000000 9
keyboard office 125000000 10

ans: 9 

1
18 1000000000
processor 3500_MHz 125000000 5
processor 4200_MHz 125000000 7
processor 5000_MHz 126000000 9
processor 6000_MHz 126000000 12
memory 1_GB 125000000 3
memory 2_GB 125000000 6
memory 4_GB 125000000 12
mainbord all_onboard 125000000 10
harddisk 250_GB 125000000 10
harddisk 500_FB 125000000 12
casing midi 125000000 10
monitor 17_inch 125000000 5
monitor 19_inch 125000000 7
monitor 20_inch 125000000 9
monitor 22_inch 125000000 12
mouse cordless_optical 125000000 12
mouse microsoft 125000000 9
keyboard office 125000000 10

ans: 7


2
18 1000000000
processor 3500_MHz 125000000 5
processor 4200_MHz 125000000 7
processor 5000_MHz 125000000 9
processor 6000_MHz 125000000 12
memory 1_GB 125000000 3
memory 2_GB 125000000 6
memory 4_GB 125000000 12
mainbord all_onboard 125000000 10
harddisk 250_GB 125000000 10
harddisk 500_FB 125000000 12
casing midi 125000000 10
monitor 17_inch 125000000 5
monitor 19_inch 125000000 7
monitor 20_inch 125000000 9
monitor 22_inch 125000000 12
mouse cordless_optical 125000000 12
mouse microsoft 125000000 9
keyboard office 125000000 10
18 1000000000
processor 3500_MHz 125000000 5
processor 4200_MHz 125000000 7
processor 5000_MHz 126000000 9
processor 6000_MHz 126000000 12
memory 1_GB 125000000 3
memory 2_GB 125000000 6
memory 4_GB 125000000 12
mainbord all_onboard 125000000 10
harddisk 250_GB 125000000 10
harddisk 500_FB 125000000 12
casing midi 125000000 10
monitor 17_inch 125000000 5
monitor 19_inch 125000000 7
monitor 20_inch 125000000 9
monitor 22_inch 125000000 12
mouse cordless_optical 125000000 12
mouse microsoft 125000000 9
keyboard office 125000000 10

ans :
9
7


1
18 1000000000
processor 3500_MHz 125000000 1
processor 4200_MHz 125000000 0
processor 5000_MHz 126000000 0
processor 6000_MHz 126000000 1
memory 1_GB 125000000 0
memory 2_GB 125000000 0
memory 4_GB 125000000 1
mainbord all_onboard 125000000 1
harddisk 250_GB 125000000 1
harddisk 500_FB 125000000 0
casing midi 125000000 1
monitor 17_inch 125000000 1
monitor 19_inch 125000000 0
monitor 20_inch 125000000 0
monitor 22_inch 125000000 0
mouse cordless_optical 125000000 0
mouse microsoft 125000000 1
keyboard office 125000000 1

ans : 1

*/