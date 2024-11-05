#include <bits/stdc++.h>
using namespace std;
 
const int mxN = 1e6;
int n, p[2*mxN+3];
char c[2*mxN+3];
 
int main() {
 
    string s;
    cin >> s;
 
    int n = s.size();
    c[0] = '!';
    c[1] = '*';
    for(int i = 0; i<n; i++) {
        c[2*i+2] = s[i];
        c[2*i+3] = '*';
    }
    c[2*n+2] = '@';
    int d =0;
    for(int i = 1; i<=n*2+2; i++) {
        if( i<=d+p[d]) {
            p[i] = min( p[2*d-i], d+p[d]-i);
        }
        while( c[i-p[i]]==c[i+p[i]]) {
            ++p[i];
        }
        --p[i];
        if( i+p[i]>d+p[d]) {
            d=i;
        }
    }
    array<int,2> ans{0};
    for(int i=1; i<=2*n+2; i++) {
        ans = max(array<int,2> {p[i],(i-p[i])/2}, ans);
    }
    for(int i=ans[1]; i<ans[1]+ans[0]; i++) {
        cout  << s[i];
    }
}
