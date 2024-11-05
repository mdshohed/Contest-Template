#include <bits/stdc++.h>
using namespace std;

int lower_binary_search(int ara[], int l, int h, int x) {

    int index = -1, low = l, hi = h, mid;
    while(low<=hi) {
        mid = (low+hi)/2;
        if( x == ara[mid] ){
            index = mid;
            hi = mid - 1;
        }
        else if ( ara[mid] < x ) low = mid + 1;
        else hi = mid - 1;
    }
    return index;
}

int main() {
    while(1){
        int n;
        cin >> n;
        int ara[100];
        for (int i = 0; i<n; i++) cin >> ara[i];
        sort(ara, ara+n);
        int m;
        cin >> m;
        int x = lower_binary_search(ara, 0, n-1, m);
        cout << x << endl;
    }
    return 0;
}
