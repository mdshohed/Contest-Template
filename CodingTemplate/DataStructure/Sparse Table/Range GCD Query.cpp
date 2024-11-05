#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;
const int k = 17;

int st[mx][k], ara[mx];

int main() {
    //freopen ( "in.txt", "r", stdin );

    int n;
    cin >> n;
    for (int i = 0; i<n; i++ ) {
        cin >> ara[i];
    }
    for (int i = 0; i<n; i++ ) {
        st[i][0] = ara[i];
    }

    for (int j = 1; j<=k; j++) {
        for (int i = 0; i+(1<<j)<=n; i++) {
            st[i][j] = __gcd( st[i][j-1],st[ i+(1<<(j-1))][j-1]);
        }
    }

    int x ;
    cin >> x;
    while (x--) {
        int a,b;
        cin >> a >> b;
        int j = log2(b-a+1);
        cout << __gcd( st[a][j], st[ b-(1<<j)+1 ][j] ) << endl;

    }
}
