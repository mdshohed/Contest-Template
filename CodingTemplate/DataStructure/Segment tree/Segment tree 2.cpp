#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;
int ara[mx];

struct node {
    int sum = 0, prop = 0;
}tree[mx*3];

void build(int node, int l, int r) {
    if ( l==r ) {
       // tree[node].prop = 0;
        tree[node].sum = ara[l];
        cout << ara[l] << " ";
        return ;
    }
    int mid = (l+r)/2;
    build( node*2,l, mid);
    build( node*2+1, mid+1,r);
//    tree[node].prop = 0;
//    tree[node].sum = 0;
    tree[node].sum = tree[node*2].sum+tree[node*2+1].sum;
}

void update( int node, int l,int r, int i, int j, int k) {
    if ( i>r||j<l) return;
    if ( i<=l&&j>=r) {
        tree[node].sum += ((r-l+1)*k);
        tree[node].prop += k;
        return;
    }
    int mid = (l+r)/2;
    update( node*2, l, mid, i, j, k);
    update( node*2+1, mid+1, r, i, j, k);
    tree[node].sum = tree[node*2].sum+tree[node*2+1].sum+(r-l+1)*tree[node].prop;
}

int sum(int node, int l, int r , int i, int j, int carry = 0) {
    if ( i>r||j<l) return 0;
    if ( l>=i && r<=j ) {
        cout << tree[node].sum << " ";
        return tree[node].sum +carry*( r-l+1);
    }
    int mid = (l+r)/2;
    return sum( node*2, l, mid,i, j,carry+tree[node].prop) + sum( node*2+1, mid+1, r, i, j, carry+tree[node].prop);
}

int main() {
    freopen( "in.txt", "r", stdin );

    int n;
    cin >> n;
    for (int i = 1; i<=n; i++) {
        cin >> ara[i];
    }

    build(1, 1,n);
    cout << endl;

    for (int i = 1; i<=n*3; i++) {
        cout << tree[i].sum << " ";
    }
    cout << endl;

    update( 1, 1, n,1, 4, 5);
    for (int i = 1; i<=n*3; i++) {
        cout << tree[i].sum << " ";
    }
    cout << endl;
    return 0;
}
