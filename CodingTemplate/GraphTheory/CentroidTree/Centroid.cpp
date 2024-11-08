#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define getbit(x,i) (((x)&(1ll<<(i))) != 0)
#define pii pair<int,int>
#define ll long long

const int mx = 2 * 1e6 + 7; 
vector<int> tree[mx]; 
vector<int> sub(mx);
vector<bool> vis(mx);

struct Centroid {
  vector<int> g[mx];
  vector<int> subSize;
  Centroid(){
    subSize.resize(mx); 
  }; 
  void add(int u, int v){ g[u].push_back(v), g[v].push_back(u);}
  void calc_subtree(int u, int p = -1){
    subSize[u] = 1; 
    for(int child: g[u] ){
      if( child != p ){
        calc_subtree( child, u); 
        subSize[u] += subSize[child]; 
      }
    }
  }
  int find_centroid(int u, int val, int p = -1){
    for(int child: g[u] ) {
      if( child != p && subSize[child] > val/2) {
        return find_centroid( child, val, u); 
      }
    }
    return u; 
  } 
}centroid;

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif 
    int n; 
    cin >> n; 
    for(int i = 0; i<n-1; i++){
      int u, v; 
      cin >> u >> v; 
      centroid.add( u, v ); 
    } 
    centroid.calc_subtree( 1 );
    cout << centroid.find_centroid( 1, n ) << endl; 
    return 0;
}
// https://cses.fi/problemset/task/2079/