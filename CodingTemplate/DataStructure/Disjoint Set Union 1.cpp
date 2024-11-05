#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;
int ara[mx];

void makeset(int n){
    for (int i = 1; i<=n; i++) {
        ara[i] = i;
    }
}

int Find(int u) {
    if( u==ara[u] ) return u;
    return ara[u] = Find(ara[u]);
}

int Union(int u, int v) {
    int a = Find(u);
    int b = Find(v);
    if ( a!=b) {
        ara[a] = b;
    }
}

bool isfriend(int u, int v) {
    int a = Find(u);
    int b = Find(v);
    return a==b;
   // return Find(u)==Find(v);  
}

int main() {

    int n;
    cin >> n;
    makeset(n);

    for (int i = 0; i<n; i++) {
       int x, y;
       cin >> x >> y;
       Union( x, y);
       if ( isfriend(x,y)) cout << "Friend" << endl;
       else cout << "Not Friend" << endl;
    }

    return 0;
}
