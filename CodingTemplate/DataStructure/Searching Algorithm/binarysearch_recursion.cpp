#include <bits/stdc++.h>
#define debug(x) cout<<"debug "<<x<<endl;
using namespace std;

int Binary_search(int l, int h, int ara[], int x) {
    while( l<= h ) {
        int mid = (l+h)/2;
        if ( ara[mid]==x) {
            return mid;
        }
        if ( ara[mid]<=x) {
            return Binary_search(mid+1, h, ara, x);
        }
        else {
            return Binary_search(l, mid-1, ara, x);
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int ara[100];
    for (int i = 0; i<n; i++) cin >> ara[i];
    int x;
    cin >> x;
    int m = Binary_search(0, n-1, ara, x);
    if ( m == -1 ) cout << "No" << endl;
    else cout << m << " Yes" << endl;
    return 0;
}
