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
    int n; 
    cin >> n; 
    std::vector<ll> dp(n+1);
    dp[0] = 1; 
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=6; j++) {
            if(i-j>=0) {
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
    }
    cout << dp[n] << endl; 
    return 0;   
}
// https://cses.fi/problemset/task/1633