
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct suffixArray{
  vector<int> p, c, lcp; 
  vector<pair<char,int>> a;  
  string s; 
  int n; 

  void buildSuffixArray() {
    for(int i = 0; i<n; i++) a[i] = {s[i], i}; 
    sort(a.begin(), a.end()); 
    for(int i = 0; i<n; i++) p[i] = a[i].second;
    c[p[0]] = 0; 
    for(int i = 1; i<n; i++) {
      if ( a[i].first==a[i-1].first) c[p[i]] = c[p[i-1]]; 
      else c[p[i]] = c[p[i -1]] + 1; 
    }
    auto countSort = [&]() {
      vector<int> cnt(n), pos(n), p_new(n); 
      for(int x: c ) cnt[x]++; 
      pos[0] = 0; 
      for(int i = 1; i<n; i++) pos[i] = pos[i-1] + cnt[i-1]; 
      for(auto x: p ) {
        int i = c[x];
        p_new[pos[i]] = x; 
        pos[i]++; 
      }
      p = p_new;  
    }; 
    for(int k = 0; (1LL << k) < n; k++) {
      for(int i = 0; i<n; i++) {
        p[i] = ( p[i] - (1LL <<k) + n ) % n; 
      }
      countSort();  
      vector<int> c_new(n); 
      c_new[p[0]] = 0; 
      for(int i = 1; i<n; i++) {
        pair<int,int> prev = { c[p[i-1]], c[(p[i-1]+(1LL <<k))%n] };
        pair<int,int> now = { c[p[i]], c[(p[i]+(1LL<<k))%n] };
        if (prev==now) c_new[p[i]] = c_new[p[i-1]];
        else c_new[p[i]] = c_new[p[i-1]] + 1; 
      }
      c = c_new;
    }
  }
  void build(string &ss) {
    s = ss + "$"; 
    n = s.size();
    p.resize(n), c.resize(n), a.resize(n), lcp.resize(n); 
    buildSuffixArray(); 
  }
  void buildLCP() {
    int cnt = 0;  
    for(int i = 0; i<n-1; i++) {
      int j = p[c[i] - 1];
      while ( s[i + cnt] == s[j + cnt]) cnt++; 
      lcp[c[i]] = cnt; 
      cnt = max( cnt - 1, 0);  
    }
  }
}suffix; 
