#include <bits/stdc++.h>
using namespace std;
 
int main() {
    //freopen("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for(int i = 0; i<k; i++){
        int u, v;
        cin >> u >> v;
        --u,--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n), ans;
    function<void(int u)> dfs = [&](int u) {
        if(vis[u]) return;
        vis[u] = 1;
        for(int v : g[u]) {
            dfs(v);
        }
    };
    for(int i = 0; i<n; i++) {
        if(!vis[i]) {
            dfs(i);
            ans.push_back(i);
        }
    }
    cout << ans.size()-1 << endl;
    for(int i = 1; i<ans.size(); i++) {
        cout << ans[0]+1 << " " << ans[i]+1 << endl;
    }
    cout << endl;
    return 0;
}
// https://cses.fi/problemset/task/1666