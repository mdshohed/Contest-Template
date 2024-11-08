#include <bits/stdc++.h>
using namespace std;
 
template<typename T>
vector<T> readv(int n){vector<T> v(n);for(auto &i:v)cin>>i;return v;}
#ifdef auto v = readv<int>(n);
#endif
#define filein(x)  freopen("in.txt","r",stdin)
#define debug(x) cerr << #x << " --> " << x << endl
#define make(x,y) make_pair(x,y)
typedef long long ll;
typedef pair<int,int> pii;
 
const int mx = 1e6+7;
const int M = 1e9+7;
map<ll,ll> f;
 
ll fib(ll n ) {
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

// https://cses.fi/problemset/task/1722/