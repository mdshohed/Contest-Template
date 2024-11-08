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
// https://cses.fi/problemset/task/1712/