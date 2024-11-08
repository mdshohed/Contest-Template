#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> pi;
typedef long long ll;
#define ar array
 
const int mxN = 2e5+7;
ll ara[mxN];
 
int main() {
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> ara[i+1];
        ara[i+1] += ara[i];
    }
    while (k--) {
        int a, b;
        cin >> a >> b;
        --a;
        cout << ara[b]-ara[a] << endl;
    }
}
// https://cses.fi/problemset/task/1646