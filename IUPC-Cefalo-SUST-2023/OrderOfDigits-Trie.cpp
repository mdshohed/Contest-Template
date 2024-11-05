#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define getbit(x,i) (((x)&(1ll<<(i))) != 0)
#define pii pair<int,int>
#define ll long long

struct TRIE{
  struct node{
    int next[10], cnt; 
    node(){
      memset(next, -1, sizeof next); 
      cnt = 0;
    }
  };
  vector<node> tree;
  TRIE(){
    tree.emplace_back(); 
  }
  int getNode(){
    int x = tree.size();
    tree.emplace_back();
    return x;
  }
  void add(ll x ){
    vector<int> v; 
    for(int i = 0; i<=18; i++){
      v.push_back(x%10), x/=10;
    }
    reverse(all(v));
    int cur = 0; 
    for(auto &c: v ){
      if( tree[cur].next[c] == -1 ){
        int tmp = getNode();
        tree[cur].next[c] = tmp; 
      }
      cur = tree[cur].next[c];
      tree[cur].cnt++; 
    }
  }
  int query(ll x, vector<int> order){
    int ans = 0;
    vector<int> v; 
    for(int i = 0; i<=18; i++){
      v.push_back(x%10);
      x/=10;
    }
    reverse(all(v));
    int cur = 0;
    for(int i = 0; i<=18; i++){
      for(int j = 0; j<10; j++){
        if( order[j] < order[v[i]] && tree[cur].next[j] != -1){
          ans += tree[tree[cur].next[j]].cnt; 
        }
      }
      cur = tree[cur].next[v[i]];
      if( cur == -1 ) break;
    }
    return ans; 
  }
}trie;


int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif 
  int n; 
  cin >> n;
  for(int i = 0; i<n; i++) {
    ll x; cin >> x;
    trie.add(x); 
  }
  vector<int> order(10); 
  int q; cin >> q;
  while(q--){
    for(int i = 0; i<10; i++){
      int x = 0; 
      cin >> x; 
      order[x] = i;  
    }
    ll x; 
    cin >> x; 
    cout << trie.query( x, order) << endl; 
  }
  return 0;
}