#include <bits/stdc++.h> 
using namespace std; 

ll nCr(ll n , ll r){
    if(n == r) return 1;
    if(n < r) return 0;
    ll ans = fac[n] * (pw(fac[r] , mod-2));
    ans %= mod;
    ans *= pw(fac[n-r] , mod-2);
    return ans%mod;
}

int main(){
  int n, r; 
  cin >> n >> r;
  int ans = nCr(n, r);
  cout << ans << endl; 
}