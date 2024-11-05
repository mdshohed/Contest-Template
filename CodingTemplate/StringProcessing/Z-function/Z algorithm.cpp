/*
resource: https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/
algorithm: Z algorithm
input:
1
mdshohedshohed
sho
output:
pattern search: 2
pattern search: 8

*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;
int z[mx];

void z_function(string pat, int n) {

    int l , r, k;
    l = r = 0;
    z[0] = 0;

    for (int i = 1; i<n; i++) {
        if (i>r) {
            r = l = i;
            while ( r<n && pat[r]==pat[r-l]) {
                r++;
            }
            z[i] = r - l;
            r--;
        }
        else {
            k = i - l;
            if ( z[k]< r-i+1) {
                z[i] = z[k];
            }
            else {
                l = i;
                while ( r<n && pat[r]==pat[r-l]) {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }
}

int pattern_search(string txt, string pat) {
    int n = txt.size();
    int m = pat.size();

    string pattern = pat  + "$"  + txt;
    int x = pattern.size();

    z_function(pattern, x);

    for (int i = 0; i<x; i++) {
        cout << z[i];
    }
    cout << endl;
    for (int i = 0; i<x; i++) {
        if ( z[i]==m) cout << "pattern search: " << i-m-1 << endl;
    }
}

int main () {
    int t;
    cin >> t;
    while (t--) {

        string txt, pat;
        cin >> txt >> pat;

        pattern_search(txt, pat);
    }
    return 0;
}
