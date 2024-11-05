#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define getbit(x,i) (((x)&(1ll<<(i))) != 0)
#define pii pair<int,int>
#define ll long long

int main() {
  ios_base::sync_with_stdio(0),cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("../in.txt", "r", stdin);
#endif 
  int tc; 
  cin >> tc; 
  while(tc--){
    ll n, p, q, x, y;
    cin >> n >> p >> q >> x >> y;
    ll cost1 = 0, cost2 = 0;
    ll temp = n, temp2 = n; 
    ll p1 = p, q1 = q;
    if((p-x*(n-1))<0){
      ll start = ( p - (x*(p/n+1)));
      temp -= (p/x+1);
      cost1 = ((p/x+1)/2.0) * ( start + p); 
      start = ( q - (y*(temp-1)));
      cost1 += ((temp)/2.0) * ( start + q); 
    }
    else {
      ll start = ( p - x*(n-1));
      cost1 = (n/2.0) * ( start + p); 
    }

    if((q-y*(n-1))<0){
      ll start = ( q - (y*(q/n+1)));
      temp -= (q/y+1);
      cost2 = ((q/y+1)/2.0) * ( start + q); 

      start = ( p - (x*(temp-1)));
      cost2 += ((temp)/2.0) * ( start + p); 

    }
    else {
      ll start = ( q - y*(n-1));
      cost2 =  (n/2.0) * ( start + q); 
    }
    
    cout << min(cost1, cost2) << endl; 
  }
  return 0;
}

