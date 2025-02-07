#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int sequence[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    int ans = 0;

    for(int i=0;i<=n;i++){ 
        vector<int> temp;
        int res = 0;

        // i까지 증가 
        for(int j=0;j<i;j++){
            if(temp.empty()) temp.push_back(sequence[j]);
            else {
                if(temp.back() < sequence[j]) temp.push_back(sequence[j]);
                else {
                    auto it = lower_bound(temp.begin(), temp.end(), sequence[j]);
                    *it = sequence[j];
                }
            }
        }

        res += temp.size();

        temp.clear();

        // i부터 감소
        for(int j=i-1;j<n;j++){
            if(j<0)j++; 
           if(temp.empty()) temp.push_back(sequence[j]);
            else {
                if(temp.back() > sequence[j]) temp.push_back(sequence[j]);
                else {
                    auto it = lower_bound(temp.begin(), temp.end(), sequence[j], greater<int>());
                    *it = sequence[j];
                }
            }
        }
        res += temp.size();
        ans = max(ans, res-1);
    }
    cout << ans;

    return 0;
}
