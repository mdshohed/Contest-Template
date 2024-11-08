#include <bits/stdc++.h>
using namespace std;
 
template<typename T>
//auto v = readv<int>(n);
vector<T> readv(int n){vector<T> v(n);for(auto &i:v)cin>>i;return v;}
#define filein(x)  freopen("in.txt","r",stdin)
#define debug(x) cerr << #x << " --> " << x << endl
#define make(x,y) make_pair(x,y)
typedef long long ll;
typedef pair<int,int> pii;
 
int dx[] = { 0, 0, -1, 1};
int dy[] = { -1, 1, 0, 0};
string ds = "LRUD";
 
const int mx = 1000+7;
vector<vector<char>> v;
int visit[mx][mx];
int dis[mx][mx];
int n, m;
 
bool bfs(pii a, pii b) {
    memset( dis, -1, sizeof(dis));
 
    queue<pii> q;
    q.push(a);
    visit[a.first][a.second] = 1;
    dis[a.first][a.second] = 0;
 
    while( !q.empty()) {
        pii u = q.front(); q.pop();
        int ix = u.first, iy = u.second;
        if ( ix==b.first && iy==b.second) {
            return true;
        }
 
        for (int i = 0; i<4; i++) {
            pii nx = {ix+dx[i],iy+dy[i]};
            int x = nx.first;
            int y = nx.second;
 
            if ( 0<=x&&x<n && 0<=y&&y<m) {
                if ( v[x][y]!='#' && !visit[x][y] ) {
                    visit[x][y] = 1;
                    dis[x][y] = i;
                    q.push(nx);
                }
            }
        }
    }
    return false;
}
 
int main() {
 
    pii a, b;
 
    cin >> n >> m;
    v.resize(n);
    for (int i = 0;i<n; i++ ) {
        v[i].resize(m);
        for (int j = 0; j<m; j++ ) {
            cin >> v[i][j];
            if ( v[i][j]=='A') {
                a =  {i,j};
            }
            if (v[i][j]=='B') {
                b = {i,j};
            }
        }
    }
 
    if ( bfs(a,b)) {
        cout << "YES" << endl;
        vector<int> ans;
        while ( a!=b) {
            int x = dis[b.first][b.second];
            ans.push_back(x);
            b = make( b.first - dx[x] , b.second - dy[x]);
        }
        reverse( ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(auto i:ans) {
            cout << ds[i];
        }
        cout << endl;
 
    }
    else cout << "NO" << endl; 
}

// https://cses.fi/problemset/task/1193
