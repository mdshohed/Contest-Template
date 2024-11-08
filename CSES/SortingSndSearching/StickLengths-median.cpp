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
  vector<int> a(n); 
  for(int &i: a ) cin >> i; 
  sort(all( a) );
  int m = a[ n/2 ];
  ll sum = 0; 
  for(int i: a ){
    sum += abs( m - i ); 
  }
  cout << sum << endl;  
  return 0;
}