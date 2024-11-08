#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define getbit(x,i) (((x)&(1ll<<(i))) != 0)
#define pii pair<int,int>
#define ll long long
 
int power(long long n, long long k, const int mod) {
  int ans = 1 % mod;
  n %= mod;
  if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}
 
const int N = 1e6 + 7; 
const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
  pw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
    pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
  }
  ip1 = power(p1, MOD1 - 2, MOD1);
  ip2 = power(p2, MOD2 - 2, MOD2);
  ipw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
    ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
  }
}
 
struct Hashing {
  int n; 
  string s; 
  vector<pair<int,int>> hs;
  Hashing(){}
  Hashing(string _s){
    n = _s.size(); 
    s = _s; 
    hs.emplace_back(0, 0);
    for(int i = 0; i<n; i++){
      pair<int,int> p;
      p.first = ( hs[i].first + 1LL * pw[i].first * s[i] % MOD1 ) % MOD1; 
      p.second = ( hs[i].second + 1LL * pw[i].second * s[i] % MOD2 ) % MOD2; 
      hs.push_back(p); 
    }
  }
  pair<int, int> get_hash(int l, int r){
    assert( 1 <= l && l <= r && r <= n ); 
    pair<int,int> ans; 
    ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL * ipw[l - 1].first % MOD1;
    ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL * ipw[l - 1].second % MOD2;
    return ans; 
  }
  pair<int,int> get_hash(){
    return get_hash(1, n );
  }
}; 
 
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif 
  prec(); 
  string s, t; 
  cin >> s >> t;
  Hashing h(s);
  auto hs = Hashing(t).get_hash();
  int n = t.size(); 
  int cnt = 0; 
  for(int i = 1; i + n - 1 <= s.size(); i++){
    if( h.get_hash(i, i+n-1) == hs) cnt++; 
  }
  cout << cnt << endl; 
  return 0;
}

// https://cses.fi/problemset/task/1753

// #include <bits/stdc++.h>
// using namespace std;
 
// vector<int> prefix_function( string s) {
//     int n = s.size();
//     vector<int> f(n);
//     f[0] = 0;
//     for ( int i = 1; i<n; i++) {
//         int j = f[i-1];
//         while ( j>0 && s[i]!=s[j] ){
//             j = f[j-1];
//         }
//         if ( s[i]==s[j] ) {
//              ++j;
//         }
//         f[i] = j;
//     }
//     return f;
// }
 
// void kmp( string s, string t) {
//     int n = s.size();
//     int m = t.size();
 
//     vector<int> prefix = prefix_function(t);
 
//     int ans = 0;
//     for (int i = 0, j =0; i<n; i++ ) {
//         while ( j>0 && s[i]!=t[j]) {
//             j = prefix[j-1];
//         }
//         if ( s[i]==t[j] ) {
//             j++;
//         }
//         if ( j==m ) {
//             ans++;
//             j = prefix[j-1];
//         }
//     }
//     cout << endl;
//     cout << ans << endl;
// }
 
// int main() {
//     string s,t;
//     cin >> s >> t;
//     kmp( s, t);
// }
