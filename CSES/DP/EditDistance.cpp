#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pii pair<ll,ll>
 
int main(){
#ifndef LOCAL
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
#else
    freopen( "in.txt", "r", stdin);
    //freopen( "out.txt","w", stdout);
#endif
    string s, t; 
    cin >> s >> t; 
    int n = s.size(), m = t.size();
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, -1));
    for(int i = 0; i<=n; i++) {
        for(int j  = 0; j<=m; j++) {
            if(i==0) dp[i][j] = j;
            else if(j==0)dp[i][j] = i;
            else if( s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = min( min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1; 
            } 
        }
    }
    cout << dp[n][m] << endl; 
    return 0;   
}

// https://cses.fi/problemset/task/1639