#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define getbit(x,i) (((x)&(1ll<<(i))) != 0)
#define pii pair<int,int>
#define ll long long

const int mx = 2e5 + 7; 
vector<int> g[mx];
vector<int> ans(mx); 
vector<int> subSize(mx); 
vector<int> maxValue(mx); 
vector<int> dist(mx); 

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif 
  int n; 
  cin >> n; 
  for(int i = 1; i<n; i++){
    int u, v; cin >> u >> v; 
    g[u].push_back(v); 
    g[v].push_back(u); 
  }
  function<void(int,int)> dfs = [&](int node, int p )->void {
    int cnt = 0; 
    for(int child : g[node] ){
      if( child != p ){
        dfs( child, node );
        cnt = max( cnt, 1 + subSize[child]);
      }
    }
    subSize[node] = cnt; 
  }; 
  
  function<void(int,int, int)> dfs2 = [&]( int node, int p, int par_ans )->void { 
    vector<int> prefixMax, suffixMax; 
    for(int child : g[node] ){
      if( child != p ){
        prefixMax.push_back(subSize[child]);
        suffixMax.push_back(subSize[child]);
      }
    }

    for(int i = 1; i<prefixMax.size(); i++) prefixMax[i] = max(prefixMax[i], prefixMax[i - 1]); 
    for(int i = (int)suffixMax.size()-2; i>=0; i--) suffixMax[i] = max(suffixMax[i], suffixMax[i + 1]); 
    
    int c_no = 0;
    for(int child : g[node]){
      if(child != p){
        int op1 = (c_no == 0) ? INT_MIN : prefixMax[c_no - 1];
        int op2 = (c_no == (int)suffixMax.size() - 1) ? INT_MIN : suffixMax[c_no + 1];
        int partial_ans = 1 + max(par_ans, max(op1,op2));

        dfs2(child, node, partial_ans);
        c_no++;
      }
    }
    ans[node] = 1 + max(par_ans, (prefixMax.empty() ? -1 : prefixMax.back()));
  }; 
  dfs( 1, 0);
  dfs2( 1, 0, -1);
  for(int i = 1; i<=n; i++){
    cout << ans[i] << " "; 
  }
  cout << endl; 
  return 0;
}

// https://cses.fi/problemset/task/1132/