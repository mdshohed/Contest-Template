#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define getbit(x,i) (((x)&(1ll<<(i))) != 0)
#define pii pair<int,int>
#define ll long long

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif 
    int tc, cases = 0; 
    cin >> tc;
    map<int,int> mp;
    vector<pair<int,int>> check;
    for(int i = 1; i<48; i++){
        int val = ceil(94/(double)i);
        check.push_back({i,val});
    }
    check.push_back({94,1});  
    while(tc--){
        cout << "Case " << ++cases << ":" << endl; 
        char a, b; 
        cin >> a >> b;
        vector<pair<int,int>> ans2; 
        for( auto x: check ){
            int row = x.first, col = x.second;
            vector<vector<char>> v(col, vector<char>(row));
            char ch = '!';
            for(int i = 0; i<col; i++ ){
                for(int j = 0; j<row; j++){
                    v[i][j] = ch; 
                    ch++; 
                    
                }
            } 
            vector<pair<int,int>> ans; 
            for(int i = 0; i<col; i++){
                for(int j = 0; j<row; j++) {
                    if(v[i][j]==a || v[i][j]==b) {
                        ans.push_back({i,j});
                    }
                }
            }
            if( ans.size() && (ans[0].second== ans [1].second)) {
                ans2.push_back({ row, col}); 
            }
        }
        for(auto val: ans2){
            cout << val.first << " " << val.second << endl; 
        }
        cout << endl; 
    }
    return 0;
}