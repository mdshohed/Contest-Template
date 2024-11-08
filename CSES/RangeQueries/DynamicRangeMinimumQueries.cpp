#include <bits/stdc++.h>
using namespace std;
 
#define inf (1<<32)
typedef long long ll;
 
const ll mx = 2e5+7;
ll ara[mx];
ll tree[mx*3];
 
void build(ll node, ll l, ll r) {
    if ( l==r ) {
        tree[node] = ara[l];
        return;
    }
    ll mid = (l+r)/2;
    build( node*2, l, mid);
    build( node*2+1, mid+1, r);
    tree[node] = min( tree[node*2],tree[node*2+1]);
}
 
void update(int node, int l,int r, int i, int k) {
    if ( i>r||i<l ) return;
    if ( i<=l&&i>=r ) {
        tree[node] = k;
        return;
    }
    int mid = (l+r)/2;
    update( node*2,l,mid, i, k);
    update( node*2+1, mid+1, r, i, k);
    tree[node] = min( tree[node*2], tree[node*2+1]);
}
 
ll min_find(ll node, ll l,ll r, ll i, ll j) {
    if ( i>r||j<l) return INT_MAX;
    if ( i<=l&&j>=r) {
        return tree[node];
    }
    ll mid = (l+r)/2;
    return min(min_find(node*2,l,mid,i,j),min_find(node*2+1,mid+1,r,i,j));
}
 
int main() {
    //freopen( "in.txt", "r", stdin );
    //ios_base::sync_with_stdio(false),cin.tie(nullptr);
 
    ll n , m;
    cin >> n >> m;
    for (int i = 1; i<=n; i++) {
        cin >> ara[i];
    }
 
    build(1,1,n);
 
    for (int i = 1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if ( a==1 ) {
            update( 1, 1, n, b, c);
        }
        if ( a==2) {
            cout << min_find( 1, 1, n,b,c) << endl;
        }
    }
    return 0;
}
// https://cses.fi/problemset/task/1649