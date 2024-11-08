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
  ll n; 
  cin >> n;
  vector<pair<ll,ll>> a(n);
  for(ll i = 0; i<n; i++) {
    cin >> a[i].first >> a[i].second; 
  }
  sort(all(a), [](auto a, auto b){
    return a.second < b.second;
  });
  ll cnt = 1; 
  ll current = a[0].second;
  for(ll i = 1; i<n; i++){
    if( current <= a[i].first ){
      current = a[i].second;
      cnt++; 
    }
  }
  cout << cnt << endl; 
  return 0;
}

// https://cses.fi/problemset/task/1629/