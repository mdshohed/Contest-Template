#include <bits/stdc++.h>
using namespace std; 
#define all(x) x.begin(), x.end()
#define pii pair<int,int> 
#define ll long long 
 
void count_sort(vector<int> &p, vector<int> &c) {
    int n = p.size(); 
    vector<int> cnt(n), pos(n), p_new(n);
    for(auto x: c ) cnt[x]++; 
    pos[0] = 0; 
    for(int i = 1; i<n; i++) {
        pos[i] = pos[i - 1] + cnt[ i - 1]; 
    }
    for(auto x: p ) {
        int i = c[x]; 
        p_new[pos[i]] = x; 
        pos[i]++; 
    }
    p = p_new; 
}
 
int main() {
    // freopen( "in.txt", "r", stdin ); 
    string s; 
    int t;
    cin >> s >> t; 
    vector<string> v(t); 
    for(string &x: v ) cin >> x; 
    s += "$"; 
    int n = s.size(); 
    vector<int> p(n), c(n); 
    vector<pair<char,int>> a(n);  
    for(int i = 0; i<n; i++) a[i] = {s[i], i }; 
    sort( all(a)); 
    for(int i = 0; i<n; i++ ) p[i] = a[i].second;
    c[p[0]] = 0; 
    for(int i = 1; i<n; i++) {
        if(a[i].first==a[i-1].first) c[p[i]] = c[p[i-1]]; 
        else c[p[i]] = c[p[i-1]] + 1; 
    } 
    int k = 0; 
    while ( (1<<k)<n) {
        for(int i = 0; i<n; i++) {
            p[i] = ( p[i] - (1<<k) + n ) % n;
        }
        count_sort(p, c);  
        vector<int> c_new(n); 
        for(int i = 1; i<n; i++) {
            pii prev = { c[p[i-1]], c[(p[i-1] + (1<<k)) % n]}; 
            pii now = { c[p[i]], c[(p[i] + (1<<k)) % n]};
            if ( prev == now ) c_new[p[i]] = c_new[p[i-1]]; 
            else c_new[p[i]] = c_new[p[i-1]] + 1; 
        }
        c = c_new; 
        k++;  
    }
    for(string str: v) {
        int l = 0, r = n-1, ans = 0; 
        while( l<=r) {
            int m = (l + r ) >> 1; 
            string text = s.substr( p[m], str.size()); 
            if ( text==str) {
                ans = 1; 
                break; 
            }
            if ( str >= text ) l = m + 1; 
            else r = m - 1; 
        }
        cout << (ans? "YES":"NO") << endl; 
    }
    return 0; 
}
 
//  https://cses.fi/problemset/task/2102/