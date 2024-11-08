#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pii pair<ll,ll>
 
const int mod = 1e9+7; 
 
int main(){
#ifndef LOCAL
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
#else
    freopen( "in.txt", "r", stdin);
    //freopen( "out.txt","w", stdout);
#endif
    ll n, s; 
    cin >> n >> s; 
    std::vector<int> a(n);
    for(int &i: a ) cin >> i;  
    vector<int> dp(s+1);
    dp[0] = 1; 
    for(int i = 1; i<=s; i++) {
        dp[i] = 0; 
        for(int j: a) {
            if ( j<=i) dp[i] = (dp[i] + dp[i - j]) % mod; 
        }
    } 
    cout << dp[s] << endl;
    return 0;   
}
// https://cses.fi/problemset/task/1635