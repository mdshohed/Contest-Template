typedef long long ll;
const int mxN = 1e5+7;
ll ara[mxN];
vector<ll> st[mxN*3];

void build(int node,int l, int r) {
    if (l==r) {
        st[node].push_back(ara[l]);
        return;
    }
    int mid = (l+r)/2;
    build(node*2, l, mid);
    build( node*2+1, mid +1, r);
    merge( st[node*2].begin(),st[node*2].end(), st[node*2+1].begin(),st[node*2+1].end(), back_inserter(st[node]) );
}

ll qry(int node, int l, int r, int i, int j, int k ) {
    if (r<i ||l>j) return 0;
    if ( i<=l&&r<=j) {
        int x = st[node].end() - upper_bound( st[node].begin(), st[node].end(), k);
        return x;
    }
    int mid = (l+r)/2;
    return qry( node*2, l, mid, i, j, k) + qry( node*2+1,mid+1, r, i, j, k);
}
