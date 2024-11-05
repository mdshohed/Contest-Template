// equal or greater value return lower_bound.
# Step 1: 
int position = lower_bound(a.begin(),a.end(), val) - a.begin();

# Step 2: 
int lower_bound(vector<int> a, int x) {
    int l = -1, r = a.size(); 
    while( 1+l<r) {
        int m  = ( l+r ) >> 1; 
        if ( a[m]<x ) l = m; 
        else r = m; 
    } 
    return r+1;   
}
