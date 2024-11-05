#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define all(x) begin(x),end(x)

const int mx = 1e5+7; 
vector<int> factCount(mx); 
vector<int> factor[mx];

void sieve() {
    for(int i = 1; i<=mx; i++) {
        for(int j = i; j<=mx; j+=i) {
            factor[j].push_back(i);
            factCount[j]++;  
        }
    }
}

int main() {
#ifdef LOCAL
    ios_base::sync_with_stdio(false),cin.tie(nullptr); 
#else
    freopen( "in.txt", "r", stdin);
    //freopen( "out.txt","w", stdout);
#endif
    sieve();
    for(int i = 1; i<150; i++){
        for(int j: factor[i]) cout << j << " ";
        cout << endl; 
        cout << factCount[i] << endl;  
    }
    return 0;
}
