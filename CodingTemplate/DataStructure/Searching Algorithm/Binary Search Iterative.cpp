#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;

int binary( int ara[], int x, int n) {
    int l = 0, r = n-1;
    while (l<=r) {
        int mid = (l+r)/2;
        if (ara[mid]==x) return mid+1;
        if ( ara[mid]<x ) {
            l = mid+1;
        }
        else r = mid-1;
    }
}

int main() {
    int n;
    cout << "Inter the array value: ";
    cin >> n;
    int ara[mx];
    for (int i = 0; i<n; i++ ) cin >> ara[i];

    sort( ara, ara+n);

    int m;
    cout << "Inter the input of Quary type how many you want: ";
    cin >> m;
    for (int i = 0; i<m; i++) {
        int x;
        cin >> x;
        cout <<  binary( ara, x, n) << endl;
    }
}
