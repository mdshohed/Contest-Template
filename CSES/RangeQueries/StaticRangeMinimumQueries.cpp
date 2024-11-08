#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int mxN = 2e5+7;
int n, q;
ll  ara[mxN];
 
struct node{
    ll mn;
}st[1<<19];
 
void upd( int l,int x, int i = 1, int l2 = 0, int r=n-1) {
    if (l2==r) {
        st[i].mn=x;
        return;
    }
    int m2 = (l2+r)/2;
    if ( l<=m2 ) upd( l, x, i*2, l2, m2);
    else upd( l, x, 2*i+1, m2+1, r );
    st[i].mn =min(st[i*2].mn,st[2*i+1].mn);
}
 
ll qry(int l, int r, int i = 1, int l2 = 0, int r2 = n-1) {
    if ( l<=l2 && r2<=r ) {
        return st[i].mn;
    }
    int m2 = (l2+r2)/2;
    return min ( l<=m2?qry(l,r,2*i,l2,m2):(int)1e9,
                 m2<r? qry(l,r,2*i+1,m2+1,r2):(int)1e9);
}
 
int main() {
    //freopen ( "in.txt","r",stdin);
 
    cin >> n >> q;
    for ( int i = 0; i<n; i++) {
        cin >> ara[i];
        upd(i,ara[i]);
    }
 
    while (q-- ) {
        int a, b;
        cin >> a >> b;
        --a,--b;
        cout << qry(a,b) << endl;
    }
}

// https://cses.fi/problemset/task/1647