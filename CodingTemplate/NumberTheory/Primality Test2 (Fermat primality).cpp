/*
Time complexity: O(k Log n)
algorithm: Fermal primality 
input:
output:
*/
#include <bits/stdc++.h>
using namespace std; 

#define ll long long 

bool fermatPrimality(ll n) {
    
    auto binpow = [&](ll a, ll p,int mod) {
        p %=mod;
        ll sum = 1; 
        while (p) {
            if(p&1) sum = (1LL*a*sum) % mod; 
            a = (a*1LL*a) % mod;
            p >>= 1;  
        }
        return sum; 
    }; 
    
    if(n<2) return 0;
    if (n==2||n==3) return 1;
    if (n%2==0) return 0; 
    for(ll i = 0; i<n; i++) {
        ll a = 2 + rand()%(n-3); 
        if (binpow(a,n-1,n)!=1) return false; 
    }
    return true;
}

int main() {
    freopen("in.txt", "r", stdin );
    int cnt = 0;  
    for(int i = 1; i<100; i++) {
        if ( fermatPrimality(i)) cout << i << " is Prime" << endl, cnt++; 
    }
    cout << cnt << endl; 
    cout << endl; 
}



