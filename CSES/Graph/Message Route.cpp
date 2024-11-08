// https://cses.fi/problemset/task/1667
#include <bits/stdc++.h>
using namespace std;
 
const int mx = 1e5+7;
vector<int> adj[mx];
int parent[mx], visit[mx];
int n, m;
 
void bfs() {
    memset(visit,0,sizeof(visit));
    memset(parent,-1,sizeof(parent));
    queue<int> q;
    q.push(0);
    visit[0] = 1;
    bool k = 0;
    while ( !q.empty() ) {
        int u = q.front(); q.pop();
        if ( u==n-1) k = 1;
        for(auto v: adj[u]) {
            if (!visit[v]) {
                parent[v] = u;
                q.push(v);
                visit[v] = 1;
            }
        }
    }
    if (k) {
        vector<int> ans;
        ans.push_back(n);
        int x = n-1;
        while (1) {
            x = parent[x];
            if (x==-1) break;
            ans.push_back(x+1);
        }
        cout << ans.size() << endl;
        reverse(ans.begin(),ans.end());
        for (int i = 0; i<(int)ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else cout << "IMPOSSIBLE" << endl;
}
 
signed main() {
    //freopen( "in.txt", "r", stdin );
    ios::sync_with_stdio(false),cin.tie(nullptr);
 
    cin >> n >> m;
    for (int i = 0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs();
    return 0;
}
