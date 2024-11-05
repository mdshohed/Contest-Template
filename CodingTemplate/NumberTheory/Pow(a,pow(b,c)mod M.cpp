#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

ll binpow(ll a, ll b, int mod) {
    int sum = 1;
    a%=mod;
    while(b){
        if (b&1) sum = (sum*a)%mod;
        a = (a*a)%mod;
        b/=2;
    }
    return sum;
}

int main() {
    //filein( "in.txt");
    //ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int t;
    cin >> t;
    while ( t-- ) {
        ll a, b,c;
        cin >> a >> b >> c;
        cout << binpow( a, binpow(b, c, mod-1), mod) << endl;
    }
}

/*        
            c
          b^  
    x = A^
    
  1. y = (B ^ C) % (M - 1)
  2. Ans = (A ^ y) % M
    
*/
