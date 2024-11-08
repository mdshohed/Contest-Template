#include "bits/stdc++.h";
using namespace std;
 
const int mx = 1e6+7;
int lp[mx+1];
vector<int> v;
 
int main() {
    for(int i=2; i<mx; i++) {
        if (!lp[i]) {
            v.push_back(i);
            lp[i] = i;
        }
        for(int j=0; j<(int)v.size()&&v[j]<=lp[i]&&i*v[j]<=mx; j++) {
            lp[i*v[j]]=v[j];
        }
    }
    int n;
    cin >> n;
    while (n--) {
        map<int,int> mp;
        int x;
        cin >> x;
        while( x>1) {
            mp[lp[x]]++;
            x/=lp[x];
        }
        int ans = 1;
        for(auto i:mp ) {
            ans*=(i.second+1);
        }
        cout << ans << endl;
    }
}
// https://cses.fi/problemset/task/1713/