#include "bits/stdc++.h";
using namespace std;
 
const int mx = 1e6+7;
int c[mx];
 
int main() {
    int n;
    cin >> n;
    for(int i =0; i<n; i++) {
        int x; cin >> x;
        ++c[x];
    }
    int d = 0;
    for(int i=mx; i; --i) {
        int d = 0;
        for(int j = i; j<=mx; j+=i) {
            d +=c[j];
        }
        if (d>1) {
            cout << i;
            break;
        }
    }
}

// https://cses.fi/problemset/task/1081/