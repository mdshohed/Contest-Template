#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pii pair<ll,ll>
 
int CoinChange(vector<int> a, int n, int unit) {
    vector<vector<int>> dp(n+1, vector<int>(unit+1));
    int mod = 1e9+7; 
    for(int i = 0; i<=n; i++) dp[i][0] = 1; 
    for(int i = 1; i<=n; i++) {
        for(int j = 0; j<=unit; j++) {
            if ( j<a[i-1] ) {
                dp[i][j] = (dp[i-1][j]%mod);
            }
            else {
                dp[i][j] = (dp[i-1][j] + dp[i][ j - a[i-1]])%mod;
            }
        }
    }
    return (dp[n][unit]%mod);
}
 
int main(){
#ifndef LOCAL
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
#else
    freopen( "in.txt", "r", stdin);
    //freopen( "out.txt","w", stdout);
#endif
    int n, sum; 
    cin >> n >> sum; 
    vector<int> a(n); 
    for(int &i: a ) cin >> i; 
    cout << CoinChange(a, n, sum) << endl; 
    return 0;   
}
// https://cses.fi/problemset/task/1636