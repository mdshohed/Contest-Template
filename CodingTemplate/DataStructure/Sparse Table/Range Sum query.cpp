#include <bits/stdc++.h>
using namespace std;

const int k = 17;
const int mx = 1e5+7;

int ara[mx], st[mx][k];

int main() {

    int n;
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> ara[i];
    }

    for (int i = 0; i<n; i++ ) {
        st[i][0] = ara[i];
    }

    for ( int j = 1; j<=k; j++ ) {
        for (int i = 0; i+(1<<j)<=n; i++ ) {
            st[i][j] = st[i][j-1] + st[ i + (1<<(j-1))][j-1];
        }
    }

    while (1) {
        int sum = 0;
        int l, r;
        cin >> l >> r;
        l--,r--;
        
        for(int j = k; j>=0; j--) {
            if ( (1<<j)<= r-l+1 ) {
                sum += st[l][j];
                l += 1<<j;
            }
        }
        cout << sum << endl;  
    }

}
