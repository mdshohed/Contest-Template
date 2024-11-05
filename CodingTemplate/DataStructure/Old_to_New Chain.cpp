#include <bits/stdc++.h>
using namespace std;

#define input(x) freopen(x, "r", stdin )
#define fastio() ios::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;


int main() {
    //input( "in.txt");
    //ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    map<int,int> mp;

    for(int i = 0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        if ( mp.find(x)==mp.end() ) {
            mp[y] = x;
        }
        else {
            int t = mp[x];
            mp.erase(x);
            mp[y] = t;
        }
    }
    for (auto i:mp) {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
}

