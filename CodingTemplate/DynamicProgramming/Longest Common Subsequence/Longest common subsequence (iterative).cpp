#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define CLR(x,y) memset( x,y,sizeof(x))
#define FOR(x,n) for(int i = x; i<n; i++)

typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mp;

const int mx = 1e5+7;

int main( ) {
    string s, m;
    cin >> s >> m;
    int ara[s.size()+1][m.size()+1];

    for (int i=0; i<=s.size(); i++){
        for (int j=0; j<=m.size(); j++){
            if ( i ==0 || j ==0 )
                ara[i][j] = 0;
            else if ( s[i-1]==m[j-1]) {
                ara[i][j] = ara[i-1][j-1]+1;
            }
            else {
                ara[i][j] = max(ara[i][j-1],ara[i-1][j]);
            }
        }
    }
    cotu << ara[n][m] << endl; 

    return 0;
}
