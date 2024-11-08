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
    std::vector<std::vector<char>> grid(n,std::vector<char>(n));
    vector<vector<int>> dp(n,vector<int>(n));
    for(auto& i: grid) {
        for(auto& j: i) cin >> j; 
    }
    if(grid[0][0]=='*') {
        cout << 0 << endl; 
        return 0; 
    }
    dp[0][0] = 1; 
    int flag = 0; 
    for(int i = 1; i<n; i++) {
        if(grid[i][0]=='*') {
            dp[i][0] = 0; 
            continue;
        } 
        dp[i][0] = dp[i-1][0];
    }
    for(int i = 1; i<n; i++) {
        if(grid[0][i]=='*') {
            dp[0][i] = 0; 
            continue;
        } 
        dp[0][i] = dp[0][i-1];
    }
    for(int i = 1; i<n; i++) {
        for(int j = 1; j<n; j++) {
            if(grid[i][j]=='*') continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod; 
        }
    }
    cout << dp[n-1][n-1] << endl; 
    return 0;   
}

// https://cses.fi/problemset/task/1638