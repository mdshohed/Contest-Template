#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define getbit(x,i) (((x)&(1ll<<(i))) != 0)
#define pii pair<int,int>
#define ll long long

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif 
    int tc, cases = 0;
    cin >> tc; 
    while(tc--){
      cout << "Case " << ++cases << ":" << endl; 
      double d; 
      cin >> d; 
      double x = 1.7368 - d; 
      cout << x << endl;  
    }
    return 0;
}