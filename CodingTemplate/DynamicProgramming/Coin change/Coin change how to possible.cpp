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

ll coin_change(int ara[], int m, int n ) {
    int table[n+1];
    CLR( table, 0);
    table[0] = 1;
    for (int i=0; i<m; i++){
        for (int j =ara[i]; j<=n; j++){
            table[j] += table[j-ara[i]];
        }
    }
    if ( table[n] == 0) return -1;
    else return table[n];
}

int main(){
    int n,m;
    cin >> n >> m;
    int ara[100];
    for (int i = 0; i<m; i++){
        cin >> ara[i];
    }
    cout << coin_change(ara, m, n) << endl;
    return 0;
}
