#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    function<ll(ll,ll,ll&,ll&)> egcd = [&](ll a, ll b, ll &x, ll &y){
        if(b==0){
            x = 1, y = 0; return a;
        }
        ll x1, y1; 
        ll d = egcd(b, a%b, x1, y1);
        x=y1, y = x1 - y1*(a/b);
        return d; 
    };
    ll a, b; 
    while( cin >> a >> b ){
        ll x, y; 
        int ans = egcd(a, b, x, y);
        cout << x << " " << y << " " << ans << endl;
    }
    return 0;
}

//uva 10104 - Euclid Problem
