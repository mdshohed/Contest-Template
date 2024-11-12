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
    int tc; 
    cin >> tc; 
    while(tc--){
      int a, b, c;
      cin >> a >> b >> c;
      // Semi-perimeter:
      double s = ( a + b + c ) / 2;
      // Area using Heron's formula:
      double area = sqrt( s * ( s - a ) * ( s - b ) * ( s - c ) );
      // Radius of the incircle:
      double r = area /(double)s;
       
      cout << (r*r) << endl;  
    }
    return 0;
}