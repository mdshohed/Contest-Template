
#include <bits/stdc++.h>
using namespace std;
 
template<typename T>
vector<T> readv(int n){vector<T>v(n);for(auto &i:v)cin>>i;return v;}
#ifdef auto v = readv<int>(n);
#endif
#define input(x)  freopen("in.txt","r",stdin)
#define debug(x) cerr << #x << " --> " << x << endl
#define make(x,y) make_pair(x,y)
#define ar array
#define ll long long
typedef pair<ll,ll> pi;
 
const int mxN = 1e5+7;
vector<int> adj[mxN];
int vis[mxN], vis2[mxN];
vector<int> ans;
 
void dfs(int u) {
    if ( vis[u]) return;
    vis[u] = 1;
    vis2[u] = 1;
    for(int v:adj[u]) {
        if (vis2[v]) {
            cout << "IMPOSSIBLE" << endl;
            exit(0);
        }
        dfs(v);
    }
    vis2[u] = 0;
    ans.push_back(u);
}
 
int main() {
    //input( "in.txt");
    // ios_base::sync_with_stdio(false),cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
    for (int i=0, x, y; i<m; i++){
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i<=n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    reverse( ans.begin(), ans.end());
    for(int i = 0; i<ans.size(); i++ ) {
        cout << ans[i] << " ";
    }
}
// https://cses.fi/problemset/task/1679