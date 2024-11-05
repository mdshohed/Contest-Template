#include <bits/stdc++.h>

using namespace std;

const int mx = 1e5+7;
int ara[mx], table[mx][20];

int main() {
    //freopen ( "in.txt", "r", stdin );

    int n;
    cin >> n;
    for (int i = 0; i<n; i++ ) cin >> ara[i];

    for ( int i = 0; i<n; i++ ) {
        table[i][0] = i;
    }

    for (int j = 1; (1<<j)<=n; j++) {
        for (int i = 0; i+(1<<j)-1<n; i++ ) {
            if ( ara[table[i][j-1]] < ara[ table[i + (1<<(j-1))][j-1]]) {
                table[i][j] = table[i][j-1];
            }
            else {
                table[i][j] = table[ i+(1<<(j-1))][j-1];
            }
        }
    }

    int x;
    cin >> x;
    for (int i = 0; i<x; i++ ) {
        int l, r;
        cin >> l >> r;
        int len = r- l + 1;
        int k = log2(len);
        cout  << min( ara[ table[l][k]], ara[ table[ l +len -(1<<k)][k]]) << endl;
    }
}
