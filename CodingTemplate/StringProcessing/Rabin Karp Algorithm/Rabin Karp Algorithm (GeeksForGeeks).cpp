#include <bits/stdc++.h>
using namespace std;

#define d 256
vector<int> v;
int mod = 101;

int rk(string a, string b ) {
    int n = a.size();
    int m = b.size();
    int p = 0, t = 0, pow = 1;

    for (int i = 0; i<m-1; i++ ) {
        pow = ( pow*d ) % mod;
    }

    for (int i = 0; i<m; i++ ) {
        p = ( d*p + a[i])%mod;
        t = ( d*t + b[i])%mod;
    }

    int ans = 0;
    for (int i = 0; i<=n-m; i++) {
        if ( p==t ) {
            int j = 0;
            for (j = 0; j<m; j++) {
                if ( a[i+j]!= b[j]) break;
            }
            if ( j==m ) {
                ans++;
                cout << i+1 << " ";
            }
        }
        if ( i<n-m) {
            p = ( d* (p-a[i]*pow) + a[i+m]) % mod;
            if ( p<0) {
                p = ( p + mod);
            }
        }
    }
    cout << endl;
    return ans;
}

int main() {
    int n; 
    cin >> n; 
    for (int i = 0; i<n; i++ ) {
        string a, b;
        cin >> a >> b;
        cout << rk(a, b) << endl;
    }
}
