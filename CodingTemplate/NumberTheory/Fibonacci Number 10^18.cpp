#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6+7;
const int M = 1e9+7;
map<ll,ll> f;

ll fib(ll n ) {
    cout << 1 << " ";
    if (f.count(n)) return f[n];
    ll k = n/2;
    if ( n%2==0) {
        return f[n] = (fib(k)*fib(k) + fib(k-1)*fib(k-1))%M;
    }
    else {
        return f[n] = (fib(k)*fib(k+1) + fib(k-1)*fib(k))%M;
    }
}

int main() {

    ll n;
    cin >> n;
    f[0] = f[1] = 1;
    cout << ( n==0? 0:fib(n-1)) << endl;
}



/*
 Resourse:https://codeforces.com/blog/entry/14516
*/
