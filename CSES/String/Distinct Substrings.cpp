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
    //freopen( "in.txt", "r", stdin ); 
    string s; 
    int t;
    cin >> s;  
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
    vector<int> lcp(n);
    int cnt = 0;  
    for(int i = 0; i<n-1; i++) {
        int x = c[i];
        int j  = p[x -1]; 
        while ( s[i + cnt] == s[j + cnt]) cnt++; 
        lcp[x] = cnt; 
        cnt = max( cnt - 1, 0 ); 
    }
    ll sum = 0; 
    for(int i = 1; i<n; i++) {
        string text = s.substr( p[i], n - p[i]);
        int x  = lcp[i];
        int y = text.size() - 1; 
        sum += ( y - x);  
    }
    cout << sum << endl; 
    return 0; 
}
 
//  https://cses.fi/problemset/task/2105/
