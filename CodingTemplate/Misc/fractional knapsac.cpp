#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define EMPTY_VALUE -1
#define CLR(x,y) memset( x,y,sizeof(x))
#define FOR(x,n) for(int i = x; i<n; i++)
#define read(x) freopen(x, "r", stdin);
#define write(x) freopen( x, "w", stdout);

typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mp;

const int MOD = 1e9+7;
const int mx = 1e2+7;

struct item{
    double w, p, u;
};

bool com(item a, item b){
    return a.u > b.u;
}

int main() {
    //freopen( "in.txt", "r", stdin );
    int n,w;
    cin >> n >> w;
    item ara[1000];
    for (int i = 0; i<n; i++){
        cin >> ara[i].w >> ara[i].p;
        ara[i].u = ara[i].p /ara[i].w;
    }

    sort (ara,ara+n, com);
    
    int maximum = 0;
    for (int i = 0; i<n; i++) {
        if ( w>ara[i].w ){
            maximum += ara[i].p;
            w -= ara[i].w;
        }
        else {
            maximum += w*ara[i].u;
            w = 0;
        }
    }
    cout << "maximum price: " << maximum << endl;
    return 0;

}
