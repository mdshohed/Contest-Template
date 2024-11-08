#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
 
int main(){
#ifdef LOCAL
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
#else
    freopen( "in.txt", "r", stdin);
    //freopen( "out.txt","w", stdout);
#endif
    int n, x;  
    cin >> n >> x; 
    std::vector<int> a(n);
    for(int &i: a) cin >> i; 
    int m = n/2; 
    vector<ll> left, right; 
    for(int i = 0; i<(1<<m); i++) {
        ll sum = 0; 
        for(int j = 0; j<m; j++){
            if( i & (1<<j)) {
                sum += a[j];
            }
        } 
        left.push_back(sum);  
    } 
    for(int i = 0; i<(1<<n-m); i++) {
        ll sum = 0; 
        for(int j = 0; j<(n-m); j++) {
            if(i&(1<<j)) {
                sum += a[m+j]; 
            }
        }
        right.push_back(sum); 
    }
    for(int i: left) cout << i << " ";
      cout << endl;
      for(int i: left) cout << i << " ";
      cout << endl;
    sort(all(right));
    ll count = 0; 
    for(int i = 0; i<left.size(); i++){
        count += upper_bound(all(right), x - left[i]) - lower_bound(all(right), x - left[i]); 
    }
    cout << count << endl;  
    return 0; 
}