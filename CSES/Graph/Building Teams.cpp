// https://cses.fi/problemset/task/1668

#include <bits/stdc++.h>
using namespace std;
 
#define input(x)  freopen("in.txt","r",stdin)
 
const int mxN = 1e5+7;
vector<int> adj[mxN];
int vis[mxN];
int c[mxN];
 
void bipertite(int u, int cu = 0) {
    if ( ~c[u] ) {
        if ( c[u]^cu) {
            cout << "IMPOSSIBLE" << endl;
            exit(0);
        }
        return;
    }
    c[u] = cu;
    for(int v:adj[u]) {
        bipertite(v, cu^1);
    }
}
 
int main() {
    //input( "in.txt");
    // ios_base::sync_with_stdio(false),cin.tie(nullptr);
 
 
    int n, m;
    cin >> n >> m;
    for (int i = 0,x,y; i<m; i++ ) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    memset(c, -1,sizeof(c));
 
    for(int i = 1; i<=n; i++ ) {
        if ( c[i]<0 ) {
            bipertite(i);
        }
    }
    for (int i = 1; i<=n; i++) {
        cout << c[i]+1 << " ";
    }
 
}
