/*
time complexity: O(logn)
algorithm: binary Exponentiation
*/
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7; 
int binpow(int a, int b) {
    a %=mod; 
    int sum = 1;
    while (b) {
        if (b&1) sum = (sum * 1LL * a) % mod; 
        a = (a * 1LL * a) % mod;
        b >>= 1; 
    }
    return sum; 
}

int main() {
#ifdef Local
    ios_base::sync_with_stdio(false),cin.tie(nullptr); 
#else
    freopen( "in.txt", "r", stdin);
    //freopen( "out.txt","w", stdout);
#endif
    int a, b; 
    cin >> a >> b; 
    cout << binpow( a, b) << endl; 
    return 0; 
}
  
