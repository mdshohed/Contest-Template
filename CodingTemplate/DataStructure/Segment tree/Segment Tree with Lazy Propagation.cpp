#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+7;
typedef long long ll;
ll ara[mxN], n, q;

struct node {
    ll s,lz,mn, mx;
}st[mxN*3];

void propagate( int node, int l, int r) {
    if ( st[node].lz!=0 ) {
        st[node].s += (r-l+1)*st[node].lz;

        if  ( l!=r ) {
            st[node*2].lz += st[node].lz;
            st[node*2+1].lz += st[node].lz;
        }
        st[node].lz = 0;
    }
}

void build(int node, int l, int r) {
    if ( l==r) {
        st[node].s = ara[l];
        return;
    }
    ll mid = (l+r)/2;
    build( node*2, l, mid);
    build ( node*2+1, mid+1, r);
    st[node].s = st[node*2].s + st[node*2+1].s;
    st[node].lz = 0;
}

void update(int node, int l, int r, int i, int j, int x) {

    propagate( node, l, r);
    if (  r<i || l>j || l>r ) return;

    if ( i<=l&&r<=j ) {
        st[node].lz +=x;
        propagate( node, l, r);
        return;
    }
    ll mid = (l+r)/2;
    update( node*2, l, mid, i, j, x);
    update( node*2+1, mid+1, r, i, j, x);
    st[node].s = st[node*2].s + st[node*2+1].s;
}

ll qry(int node, int l, int r, int i, int j ) {
    if ( r<i || l>j || l>r ) return 0;
    propagate( node,l,r);
    if ( i<=l && r<=j ) {
        return st[node].s;
    }
    ll mid = (l+r)/2;
    ll sum = qry(node*2, l, mid, i, j);
    ll sum2 = qry(node*2+1,  mid+1, r, i, j);
    return ( sum + sum2 );
}

int main() {
    //freopen ( "in.txt", "r", stdin );

    cin >> n >> q;
    for (int i = 1; i<=n; i++) cin >> ara[i];

    build( 1, 1, n);

    while (q--) {

        ll a, b, c,u;
        cin >> a;
        if ( a==1 ) {
            cin >> b >> c >> u;
            update( 1, 1, n, b, c, u);
        }
        else   {
            cin >> b;
            cout << qry(1, 1, n, b, b) << endl;
        }
    }
}
