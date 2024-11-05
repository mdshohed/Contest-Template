#include <bits/stdc++.h>
using namespace std;

int dp[1000];
int fib(int n) {
    if ( n == 0) return n;
    if ( n == 1) return n;
    if ( dp[n] != -1) {
        return dp[n];
    }
    else {
        dp[n] =  fib(n-1) + fib(n-2);
        return dp[n];
    }
}

int main() {
    memset( dp , -1, sizeof(dp));
    int n;
    cin >> n;
    fib(n);
    for(int i = 0; i<n; i++) {
        cout << dp[i] << " ";
    }
    return 0;
}
