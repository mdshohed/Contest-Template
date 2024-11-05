/*
    Time Complexity: Suffix Array:O(n log^2n) & Longest common prefix: O(nlogn) 
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;
int ara[32][mx], n,stp, cnt, B[mx];
string s;
int lcp[mx];

struct node {
    int lr[2], idx;
}l[mx];

bool cmp (node a, node b) {
    if ( a.lr[0]== b.lr[0]){
        return a.lr[1] < b.lr[1];
    }
    return a.lr[0] < b.lr[0];
}

void suffix(string s) {

    n = s.size();
    for (int i = 0; i<n; i++) {
        ara[0][i] = s[i] - 'a';
    }
    for (stp = 1, cnt = 1; cnt>>1<n; stp++, cnt<<=1 ) {
        for (int i = 0; i<n; i++ ) {
            l[i].idx = i;
            l[i].lr[0] = ara[stp-1][i];
            l[i].lr[1] = i + cnt < n ? ara[stp-1][i+cnt] : -1;
        }
        sort (l, l+n, cmp);
        for (int i = 0; i<n; i++) {
            ara[stp][l[i].idx] = i>0 && l[i].lr[0]==l[i-1].lr[0] && l[i].lr[1]==l[i-1].lr[1]? ara[stp][l[i-1].idx]:i;
        }
    }

    for (int i = 1; i<n; i++) {
        int k;
        int x = l[i].idx;
        int y = l[i-1].idx;
        lcp[i] = 0;
        for ( k = stp-1; k>=0 && x<n && y<n; k--) {
            if ( ara[k][x] == ara[k][y]) {
                x += 1 << k;
                y += 1 << k;
                lcp[i] += 1 << k;
            }
        }
    }
}


int main() {
    //freopen( "in.txt", "r", stdin );

    int t, cases = 0;
    cin >> t;
    while (t--) {
        printf( "Case %d: ",++cases);
        string s;
        int a, b;
        cin >> s >> a >> b;

        suffix(s);
        int ans = 0;
        for (int i = 0; i<n; i++ ) {
            int x = min( n-l[i].idx , b) - max (lcp[i], a-1);
            if ( x>0 )  ans+=x;
        }
        cout << ans << endl;
    }
}
