// not solved
#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define getbit(x,i) (((x)&(1ll<<(i))) != 0)
#define pii pair<int,int>
#define ll long long

int main() {
//     ios_base::sync_with_stdio(0),cin.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("../in.txt", "r", stdin);
// #endif 
    int tc, cases = 0;
    cin >> tc; 
    while(tc--){
      cout << "Case " << ++cases << ": ";
      vector<int> a,b;
      int n; cin >> n; 
      vector<vector<int>> primeFactor(n);
      map<int,int> mp; 
      auto factor = [&](int val){
        if(mp[val]) mp[val] = 0;
        for(int i = 2; i*i<=val; i++){
          if( i*i==val){
            // primeFactor[val].push_back(i);
            if(mp[i]) mp[i] = 0;   
          }
          else if( val%i==0 ){
            // primeFactor[val].push_back(val/i);
            // primeFactor[val].push_back(i);
            if(mp[i]) mp[i] = 0;
            if(mp[val/i]) mp[val/i] = 0;
          }
        }
      }; 
      for(int i = 0; i<n; i++){
        int x; cin >> x; 
        a.push_back(x); 
        mp[x]++; 
      }
      int m; cin >> m; 
      for(int i = 0; i<m; i++){
        int x; cin >> x; 
        b.push_back(x);   
        factor(x); 
      }
      int cnt = 0; 
      for(int i: a){
        if(mp[i]) cnt++;
      }
      cout << a.size() - cnt << endl;  
    }
    return 0;
}