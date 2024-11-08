/*Two Pointers*/
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
 
int main(){
#ifndef LOCAL
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
#else
    freopen( "in.txt", "r", stdin);
    //freopen( "out.txt","w", stdout);
#endif
    int n, k; 
    cin >> n >> k; 
    std::vector<pair<int,int>> a(n);
    for(int i =0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i+1; 
    } 
    sort(all(a));
    int i = 0, j = n-1;
    while(i<j) {
        ll val = a[i].first + a[j].first; 
        if(val==k) {
            cout << a[i].second << " " << a[j].second << endl; 
            return 0; 
        }
        else if( val > k ) j--; 
        else i++; 
    }
    cout << "IMPOSSIBLE" << endl; 
    return 0; 
}

// https://cses.fi/problemset/task/1640/