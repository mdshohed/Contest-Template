#include <bits/stdc++.h>
using namespace std;

const int mx = 1e4+5;
int ara[mx];

struct node {
    int mn, mx, s, lz; 
}tree[mx*3]; 

void build(int node, int l, int r){
    if ( l == r) {
        tree[node].mn = ara[l];
        tree[node].mx = ara[l];
        tree[node].s = ara[l];
        return ;
    }
    int mid = (l+r)/2;
    build(node*2, l, mid);
    build( node*2+1, mid+1,r);
    tree[node].s = tree[node*2].s + tree[node*2+1].s;
    tree[node].mn = min (tree[node*2].mn , tree[node*2+1].mn); 
    tree[node].mx = max (tree[node*2].mn , tree[node*2+1].mn); 
}


void update(int node, int l, int r, int i, int x){
    if ( r<i || l>i) return ;
    if (i<=l && r<=i) {
        tree[node].s = x;
        tree[node].mx = x;
        tree[node].mn = x;
        return;
    }
    int mid = (l+r)/2;
    update(left, l, mid, i, x);
    update(right,mid+1, r , i, x);
    tree[node].s = tree[node*2].s + tree[node*2+1].s;
    tree[node].mn = min (tree[node*2].mn , tree[node*2+1].mn); 
    tree[node].mx = max (tree[node*2].mn , tree[node*2+1].mn);
}



int qry(int node, int l, int r, int i, int j){
    if ( i > r || j<l) return 0;
    if (i<=l && r<=j) {
        return tree[node].mx;
        //return tree[node].mn;
        //return tree[node].s;
    }
    int mid = (l+r)/2;
    //return  min( query(left, l, mid, i , j),query(right,mid+1,r , i , j));
    //return  max( query(left, l, mid, i , j),query(right,mid+1,r , i , j));
    return qry( node*2,l, mid, i, j) + qry( node*2+1, mid+1, r, i,j ); 
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i<=n; i++){
        cin >> ara[i];
    }
    init(1, 1,n);
    cout << query(1,1,n, 1,5) << endl;

    update(1,1,n,2,10);
    cout << query(1, 2, n, 1, 5) << endl;
    return 0;
}
