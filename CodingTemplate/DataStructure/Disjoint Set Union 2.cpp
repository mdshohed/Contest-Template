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

const int mx = 1e5+7;
int ara[mx], Size[mx], r[mx];

void make_set(int n) {
    for (int i = 1; i<=n; i++) {
        ara[i] = i;
        Size[i] = 1;
        r[i] = 0;
    }
}

int find_set(int n) {
    if ( n==ara[n]) return n;
    return ara[n] = find_set(ara[n]);
}

void union_find(int x, int y) {
    int a = find_set(x);
    int b = find_set(y);
    if ( a!=b ) {
        if ( Size[a]<Size[b]){
            swap(a,b);
        }
        ara[b] = a;
        Size[a] += Size[b];

        if ( r[a]==r[b]) {
            r[a]++;
        }
    }
}

int main() {
    //read("in.txt");
    //ios::sync_with_stdio(false),cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    make_set(n);

    for (int i = 1; i<=m; i++) {
        char ch;
        cin >> ch;

        if( 'Q'==ch) {
            int f;
            cin >> f;

            int x =  find_set(f);
            cout << "Size: " << Size[x];
            cout << " Rank: " << r[x] << endl;
        }
        else {
            int a, b;
            cin >> a >> b;
            union_find( a, b);
        }
    }
    return 0;
}
