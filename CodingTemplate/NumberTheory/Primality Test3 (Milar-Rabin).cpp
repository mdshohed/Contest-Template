/* 
 *  time complexity: 
 *  problem: PON - Prime or Not
 *  algorithm: Milar robin
 *  
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mulmod(ll a, ll b, ll mod) {
    ll ans = 0;
    while(b) {
        if (b&1) ans = (ans+a)%mod;
        a = ( 2*a )%mod;
        b>>=1;
    }
    return ans;
}

ll binpow(ll a, ll b, ll mod ) {
    ll ans = 1;
    while ( b) {
        if ( b&1) ans = mulmod(ans,a,mod);
        a = mulmod(a,a,mod);
        b>>=1;
    }
    return ans;
}

bool composite(ll n, ll a, ll d, ll cnt) {
    ll x = binpow(a,d,n);
    if (x==1||x==n-1) {
        return false;
    }
    for (int i = 1; i<cnt; i++) {
        x = mulmod(x,x,n);
        if (x==n-1) return false;
    }
    return true;
}

bool isprime(ll n, int iter = 50) {
    if ( n<2||n==4) return false;
    if ( n==2||n==3 ) return true;

    ll cnt = 0, d = n-1;
    while ( (d&1)==0) {
        d>>=1;
        cnt++;
    }

    vector<int> v = {2,3,5,7,11,13,17,19,23,29,31,37};
    for (int a:v) {
        if ( n==a) return true;
        if ( composite(n,a,d,cnt) ) return false;
    }
    return true;
}

int main() {
    //freopen( "in.txt", "r", stdin);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        for (int i = 1; i<=n; i++) {
            if ( isprime(i)) cout << i << " is prime" << endl; 
            else cout << i << " is not prime" << endl;
        }
        cout << endl; 
    }
    return 0;
}


