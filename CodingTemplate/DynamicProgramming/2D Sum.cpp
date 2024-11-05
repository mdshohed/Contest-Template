#include <bits/stdc++.h>
using namespace std;

const int mx = 1e3+7;
int ara[mx][mx], dp[mx][mx];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cin >> ara[i][j];
        }
    }
    dp[0][0] = ara[0][0];
    for (int i = 1; i<n; i++) {
        dp[0][i] = dp[0][i-1] + ara[0][i];
    }
    for(int i = 1; i<n; i++) {
        dp[i][0] = dp[i-1][0]+ara[i][0];
    }

    for (int i = 1; i<n; i++) {
        for (int j = 1; j<n; j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + ara[i][j];
        }
    }
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
https://www.geeksforgeeks.org/prefix-sum-2d-array/
*/
