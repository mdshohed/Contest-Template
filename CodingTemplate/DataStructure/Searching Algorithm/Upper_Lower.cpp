// array start form 1 to n
auto lower = [&](int x, int pos){
    int res = -1, l = pos, r = n;
    while(l<=r){
        int m = ( l + r) / 2; 
        if( p[m] >= x) {
            r = m - 1;
            res = m; 
        }
        else l = m + 1; 
    }
    return res; 
};
auto upper = [&](int x, int pos){
    int l = pos, r = n, res = -1; 
    while( l <= r){
        int m = ( l + r) / 2; 
        if( p[m] > x ) r = m - 1; 
        else {
            l = m + 1; 
            res = m;
        }
    }
    return res; 
};
