#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define getbit(x,i) (((x)&(1ll<<(i))) != 0)
#define pii pair<int,int>
#define ll long long

const ll mx = 2e5 + 7;
vector<ll> g[mx]; 
vector<ll> subDist(mx);
vector<ll> subSize(mx);
vector<ll> ans(mx); 

int main() {
  ios_base::sync_with_stdio(0),cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif 
  int n; 
  cin >> n; 
  for(int i = 1; i<n; i++){
    ll u, v;
    cin >> u >> v;
    g[u].push_back(v); 
    g[v].push_back(u); 
  }
  // subTree distance find
  function<void(ll,ll)> dfs = [&](ll node, ll p)->void {
    subSize[node] = 1;
    for(int child: g[node] ){
      if( child != p ){
        dfs( child, node ); 
        subSize[node] += subSize[child];
        subDist[node] += subDist[child] + subSize[child];
      }
    }
  }; 
  
  // calculate sum of each node
  function<void(ll,ll)> dfs2 = [&](ll node, ll p)->void {
    // ans[node] = ans[p] - subSize[node] - subDist[node] + n - subSize[node] + subDist[node];
    // for(int child: g[node] ){
    //   if( child != p ){
    //     dfs2( child, node );   
    //   }
    // }
    for (ll child : g[node]) {
      if (child != p) {
        ans[child] = ans[node] + (n - subSize[child]) - subSize[child];
        dfs2(child, node); 
      }
    }
  }; 
  dfs( 1, -1 );
  ans[1] = subDist[1];
  // for(int child: g[1] ){
  //   dfs2( child, 1 );
  // }
  dfs2(1, -1); 
  for(int i = 1; i<=n; i++){
    cout << ans[i] << " "; 
  }
  cout << endl; 
  return 0;
}

// https://cses.fi/problemset/task/1133/