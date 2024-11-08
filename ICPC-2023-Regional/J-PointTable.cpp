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
  int n, cases = 0; 
  cin >> n; 
  while ( n-- ){
    cout << "Case " << ++cases << ": "; 
    vector<int> a(3);
    for(int i = 0 ; i< 3; i++) cin >> a[i]; 
    sort(all(a));
    if(a[2]==6 && ((a[1]==1 && a[0]==1) || (a[1]==3&&a[0]==0)) ){
      cout << "perfectus" << endl; 
    }
    else if( a[2]==4 && ((a[1]==3&&a[0]==1) || ( a[1]==2&&a[0]==1) || a[1]==4&&a[0]==0)){
      cout << "perfectus" << endl; 
    }
    else if( a[2]==3 && ( a[1]==3 && a[0]==3)){
      cout << "perfectus" << endl; 
    }
    else if( a[2]==2 && a[1]==2 && a[0]==2 ){
      cout << "perfectus" << endl; 
    }
    else {
      cout << "invalidum" << endl; 
    }
  }
  return 0;
}