#include <bits/stdc++.h>
using namespace std;

#define xx  first
#define yy  second
typedef long long ll;
const int  x = 1e4+7;
int dp[x][x];

int nCr ( int n, int r) {
    if ( r == 1) return n;
    if ( n == r) return 1;
    if ( dp[n][r] != -1) {
        return dp[n][r];
    }
    else {
        dp[n][r] = nCr(n-1, r) + nCr( n-1, r-1);
        return dp[n][r];
    }
}

int main() {

    for ( int i = 0; i<x; i++) {
        for (int j = 0; j<x; j++) {
            dp[i][j] = -1;
        }
    }
    
    int n , r;
    cin >> n >> r;
    
    cout << nCr( n, r ) << endl;
    return 0;
}
