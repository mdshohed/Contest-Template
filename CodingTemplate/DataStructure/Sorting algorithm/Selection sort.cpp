#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define EMPTY_VALUE -1
#define CLR(x,y) memset( x,y,sizeof(x))
#define FOR(x,n) for(int i = x; i<n; i++)
#define read(x) freopen(x, "r", stdin);
#define write(x) freopen( x, "w", stdout);

typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mp;

const int MOD = 1e9+7;
const int mx = 1e2+7;

int main() {
     read("input.txt");
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i<n; i++) cin >> v[i];

    for (int i = 0; i<v.size()-1; i++) {
        int index = i;
        for (int j = i+1; j<v.size(); j++) {
            if ( v[index]> v[j]) {
                index = j;
            }
        }
        if ( index!=i)  {
            swap( v[i],v[index]);
        }
    }
    for (int i = 0; i<v.size(); i++) cout << v[i] << " ";
    cout << endl;
    return 0;
}

