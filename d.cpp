#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define getbit(x,i) (((x)&(1ll<<(i))) != 0)
#define pii pair<int,int>
#define ll long long

int fx[] = {0, 0, -1};
int fy[] = {1, -1, 0};

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif 
    int tc; 
    cin >> tc; 
    while(tc--){
      int n, m; 
      cin >> n >> m;
      vector<string> a(n);
      vector<vector<bool>> flag(n, vector<bool>(m)); 
      for(int i = 0 ; i<n; i++){
        cin >> a[i]; 
      }
      int ans = 0; 
      string find = "1543"; 
      // function<void(int, int, int)> dfs = [&](int x, int y, int cnt = 0)-> void {
      //   if ( 0>x || x>=n ) return;
      //   if ( 0>y || y>=m ) return;
      //   if ( flag[x][y] ) return;
      //   if (cnt==4) {
      //     ans = 1; return;
      //   }
      //   if(a[x][y]!=find[cnt]){
      //     return; 
      //   }
      //   for (int i = 0; i<3; i++) {
      //     int dx = fx[i]+x;
      //     int dy = fy[i]+y;
      //     dfs(dx, dy, cnt+1);
      //   }
      // };
      for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
          vector<pair<int,int>> store; 
          if(a[i][j]=='1' && (!flag[i][j])){
            store.push_back({i,j});
            for (int i = 0; i<3; i++) {
              int dx = fx[i]+i;
              int dy = fy[i]+j;

            }
          } 
        } 
      }
      cout << endl; 
    }
    return 0;
}