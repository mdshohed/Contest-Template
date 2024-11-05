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

struct  job {
    double weight, price, u;
};

bool compare(job a, job b ) {
    return a.u > b.u;
}

int main() {
    //read( "in.txt");
    int w, n;
    cin >> w >> n;
    job ara[100];
    for (int i = 0; i<n; i++){
        cin >> ara[i].weight >> ara[i].price;
        ara[i].u = ara[i].price/ara[i].weight;
    }
    
    sort( ara, ara+n, compare );
    
    for (int i = 0; i<n; i++) {
        cout << ara[i].weight << " " << ara[i].price << " " << ara[i].u << endl;
    }
    cout << endl;
    
    int max_profit = 0;
    for (int i = 0; i<n; i++) {
        if ( w>ara[i].weight) {
            max_profit += ara[i].price;
            w -= ara[i].weight;
        }
        else {
            max_profit += w*ara[i].u;
            w = 0;
        }
    }
    cout << "max_profit: " << max_profit << endl;
    return 0;
}


/*

28 4
25 10
24 12
15 10
30 10

maximum = 71
*/
