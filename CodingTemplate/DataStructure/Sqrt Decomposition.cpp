/**
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define xx first
#define yy second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define clr(x,y) memset(x,y,sizeof(x))
#define read(x) freopen(x, "r", stdin);
#define write(x) freopen( x, "w", stdout);
#define db(x) cout << #x << " -> " << x << endl;
#define dbg(x) "[",#x,": ",(x),"] "

const int mx = 1e5+7;
int segment[mx], ara[mx];
int m, n ;

void preprocess() {
    int cnt = -1;
    m = sqrt(n);
    for (int i = 0; i<n; i++) {
        if ( i%m==0) {
            cnt++;
        }
        segment[cnt] += ara[i];
    }
}

int query(int l,int r) {
    int sum = 0;
    while ( l<r&& l%m!=0) {
        sum += ara[l];
        l++;
    }
    while ( l+m<=r ) {
        sum += segment[l/m];
        l+=m;
    }
    while ( l<r ) {
        sum += ara[l];
        l++;
    }
    return sum;
}

int update(int i,int val) {
    int seg = i/m;
    segment[seg] -= ara[i];
    segment[seg] += val;
    ara[i] = val;
}

int main() {
    //read( "in.txt");
    //ios::sync_with_stdio(false),cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> ara[i];
    }

    preprocess();

    for (int i = 1; i<=n; i++) {
        cout << ara[i] << " ";
    }
    cout << endl;
    for (int i = 0; i<m; i++) {
        cout << segment[i] << " ";
    }
    cout << endl;
    int a, b;
    cin >> a >> b;
    cout << query( a, b) << endl;

    int x, y;
    cin >> x >> y;
    update( x, y);
    cout << query( a, b) << endl;
     for (int i = 0; i<n; i++) {
        cout << ara[i] << " ";
    }
    cout << endl;
    for (int i = 0; i<m; i++) {
        cout << segment[i] << " ";
    }
    cout << endl;
    return 0;
}
