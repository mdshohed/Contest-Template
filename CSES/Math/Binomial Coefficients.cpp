#include "bits/stdc++.h";
using namespace std;
 
typedef long long ll;
const int mxN = 1e6+7, m = 1e9+7;
ll f[mxN], f2[mxN],v[mxN];
 
int main() {
 
    int n;
    cin >> n;
    v[1] = 1;
    for(int i = 2; i<=mxN; i++) {
        v[i] = m - m/i*v[m%i]%m;
    }
    f[0] = f2[0] = 1;
    for(int i=1; i<=mxN; i++){
        f[i] = f[i-1]*i%m;
        f2[i] = f2[i-1]*v[i]%m;
    }
    while(n--) {
        int a, b;
        cin >> a >> b;
        cout << f[a]*f2[b]%m * f2[a-b]%m << endl;
    }
}

// https://cses.fi/problemset/task/1079/