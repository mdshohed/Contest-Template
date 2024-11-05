#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define EMPTY_VALUE -1
#define CLR(x,y) memset( x,y,sizeof(x))
#define FOR(x,n) for(int i = x; i<n; i++)

typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mp;

const int mx = 1e2+7;

int lcs( int i, int j, string s, string w ){
    if ( i==s.size() || j==w.size()) return 0;
    if ( s[i]==w[j]) {
        return lcs( i+1, j+1, s, w) + 1;
    }
    else {
        return  max( lcs(i+1,j,s,w),lcs(i,j+1,s,w) );
    }
}

int main() {

    string s, w;
    cin >> s >> w;
    int i = 0, j = 0;
    cout << lcs( i ,j , s, w) << endl;
    return 0;

}
