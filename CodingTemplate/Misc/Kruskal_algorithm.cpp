#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;
};

bool operator<edge a, edge b ) {
    return a.w < b.w;
}

vector <edge> v;
int ara[100];

int find(int x) {
    if ( ara[x] == x) return x;
    return ara[x] = find( ara[x]);
}

int kruskal () {
    sort( v.begin(), v.end());

    int sz = v.size();
    int ans = 0;
    for (int i = 0; i<sz; i++) {
        if ( find(v[i].u) != find(v[i].v)) {
            ara[ara[v[i].u]] = ara[v[i].v];
            ans += v[i].w;
        }
    }
    cout << ans << '\n';
}
int main() {

    int t;
    cin >> t;
    while(t--) {
        cout <<
    }
    return 0;
}
