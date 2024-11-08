#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define getbit(x,i) (((x)&(1ll<<(i))) != 0)
#define pii pair<int,int>
#define ll long long

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif 
    int tc, cases = 0;
    scanf("%d", &tc); 
    while(tc--){
      int n; 
      scanf("%d", &n); 
      vector<int> a(n*2);
      for(int &i: a ) scanf("%d", &i); 
      int cnt = 0; 
      vector<pair<int,int>> pos = { {0,n},{n/2, n + n/2}, {n, n*2}};  
      vector<pair<int,int>> ans;
      auto sortArray = [&](int l, int r ){
        int flag = 0; 
        sort( a.begin()+l, a.begin() + r, [&](int a, int b){
          if( a < b ){
            flag = 1; 
            return a < b;
          }
          return false;  
        }); 
        if(flag) ans.push_back({l+1, r});  
      }; 
      for(int k = 0; k<3; k++){
        for(auto x: pos){
          int l = x.first, r = x.second; 
          sortArray( l, r ); 
        } 
      } 
      printf("Case %d: %d\n", ++cases, ans.size()); 
      for(auto i: ans){
        printf("%d %d\n", i.first, i.second); 
      } 
    }
    return 0;
}