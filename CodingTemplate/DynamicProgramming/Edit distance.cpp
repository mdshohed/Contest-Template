/*
algorithm: edit distance  (DP) 
input:

sunday
saturday

output:
0 1 2 3 4 5 6 7 8 
1 0 1 2 3 4 5 6 7 
2 1 1 2 2 3 4 5 6 
3 2 2 2 3 3 4 5 6 
4 3 3 3 3 4 3 4 5 
5 4 3 4 4 4 4 3 4 
6 5 4 4 5 5 5 4 3 

3

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen( "out.txt", "w", stdout);
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int dp[n+1][m+1];
    for (int i = 0; i<=n; i++) {
        for (int j = 0; j<=m; j++) {
            if ( i==0) {
                dp[i][j] = j;
            }
            else if (j==0) {
                dp[i][j] = i;
            }
            else if (a[i-1]==b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min(min( dp[i-1][j],dp[i][j-1]), dp[i-1][j-1])+1;
            }
        }
    }

    for (int i = 0; i<=n; i++) {
        for (int j = 0; j<=m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << dp[n][m] << endl;
    return 0;
}
