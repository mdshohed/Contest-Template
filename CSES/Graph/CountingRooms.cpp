/**
*/
//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <complex>
#include <unordered_map>
//Program showing a policy-based data structure.
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
//using namespace __gnu_pbds
using namespace std;
 
typedef long long ll;
 
#define xx first
#define yy second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define clr(x,y) memset(x,y,sizeof(x))
#define read(x) freopen(x, "r", stdin);
#define write(x) freopen( x, "w", stdout);
#define db(x) cout << #x << " -> " << x << endl;
 
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//*st.find_by_order(3);st.order_of_key(2);st.order_of_key(7) ordered_set st;
int fx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int fy[] = {1, -1, 0, 0, -1, 1, -1, 1};
 
const int mx = 1002;
char matrix[mx][mx];
bool visit[mx][mx];
int n, m;
 
void dfs(int x, int y) {
    if ( (x<0||x>=n) && (y<0||y>=m) ) return;
    if ( matrix[x][y]!='.' || visit[x][y] ) return;
    visit[x][y] = 1;
    for (int i = 0; i<4; i++) {
        dfs( x+fx[i], y+fy[i]);
    }
 
}
 
int main() {
    //read( "in.txt");
    ios::sync_with_stdio(false),cin.tie(nullptr);
 
    cin >> n >> m;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            cin >> matrix[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            if ( matrix[i][j]=='.' && !visit[i][j] ) {
                dfs(i,j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
// https://cses.fi/problemset/task/1192