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

const int INF = 1e5;

int coin_change(int ara[], int n, int k ){
    int table[k+1];
    table[0] = 0;
    for (int j = 1; j<=k; j++ ){
        int minimum = INF;
        for (int i=1; i<=n; i++ ){
            if ( j>= ara[i]) {
                minimum = min( minimum, 1+table[j - ara[i]] );
            }
        }
        table[j] = minimum;
    }
    if ( table[k]== 0) return -1;
    else return table[k];
}

int main(){
    int n , k;
    cin >> n >> k;
    int ara[104];
    for (int i=1; i<=n; i++) {
        cin >> ara[i];
    }
    cout << coin_change(ara, n, k) << endl;
    return 0;
}
