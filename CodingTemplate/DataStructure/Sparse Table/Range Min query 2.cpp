#include <bits/stdc++.h>
using namespace std;

const int k = 17;
const int mx = 1e5+7;

int ara[mx], st[mx][k], Log[mx];

int main() {

    int n;
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> ara[i];
    }

    for (int i = 0; i<=mx; i++) {
        Log[i] = Log[i/2] + 1;
    }
    for (int i = 0; i<n; i++ ) {
        st[i][0] = ara[i];
    }

    for ( int j = 1; j<=k; j++ ) {
        for (int i = 0; i+(1<<j)<=n; i++ ) {
            st[i][j] = min(st[i][j-1], st[ i + (1<<(j-1))][j-1]);
        }
    }

    while ( 1) {
        int l, r;
        cin >> l >> r;

        int j = Log[r-l+1];
        cout << j << " ";
        int val = min( st[l][j],st[ r -(1<<j)+1][j] );
        cout << val << endl;
    }

}
