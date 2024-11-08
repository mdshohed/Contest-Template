#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int mxN = 1e3+7;
char ara[mxN][mxN];
int st[mxN][mxN];
int n,q;
 
void upd(int idxi, int idxj, int x ) {
    for(int i = idxi+1; i<=n; i+=i&-i) {
        for(int j = idxj+1; j<=n; j+=j&-j) {
            st[i][j] += x;
        }
    }
}
 
ll qry(int idxi, int idxj) {
    ll sum = 0;
    for(int i = idxi; i; i-=i&-i) {
        for(int j=idxj; j; j-=j&-j) {
            sum+=st[i][j];
        }
    }
    return sum;
}
 
int main() {
 
    cin >> n >> q;
    for(int i = 0; i<n; i++) {
        cin >> ara[i];
        for(int j = 0; j<n; j++) {
            if ( ara[i][j]=='*') {
                upd( i, j, 1);
            }
        }
    }
 
    while (q--) {
        int a;
        cin >> a;
        if ( a==1 ) {
            int x, y;
            cin >> y >> x;
            --y,--x;
            upd( y, x, ara[y][x]=='*'?-1:1);
            if (ara[y][x]=='*') {
                ara[y][x] = '.';
                //upd( y, x, -1);
            }
            else {
                ara[y][x] = '*';
                //upd( y, x, 1);
            }
        }
        else {
            int x1, y1, x2, y2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << qry( y2, x2 ) - qry( y1-1,x2) - qry( y2, x1-1) + qry( y1-1, x1-1) << endl;
        }
    }
}
// https://cses.fi/problemset/task/1739