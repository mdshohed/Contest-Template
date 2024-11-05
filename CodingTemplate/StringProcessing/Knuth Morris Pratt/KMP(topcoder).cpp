/*
resource: https://www.topcoder.com/community/competitive-programming/tutorials/introduction-to-string-searching-algorithms/
algorithm: KMP algorithm
input:
1
mdshohed
sho
output:
3
*/
#include <bits/stdc++.h>
using namespace std;

int lps[mx];

void failure_table(string pat) {
    int m = pat.size();
    lps[0] = lps[1] = 0;
    for(int i = 2; i<=m; i++) {
        int j = lps[i-1];
        while(1) {
            if (pat[i-1]==pat[j]) { lps[i] = j+1; break; }
            if ( j==0 ) { lps[i] = 0; break; }
            j = lps[i];
        }
    }
}

int kmp(string txt, string pat ) {
    int n = txt.size();
    int m = pat.size();
    int i = 0, j = 0;
    failure_table(pat);
    for(;;) {
        if ( j==n ) return -1;
        if ( txt[j]==pat[i] ) {
            i++,j++;
            if (i==m) return j-i+1;
        }
        else if (i>0) i = lps[i];
        else j++;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string txt, pat;
        cin >> txt >> pat;
        int x = kmp(txt, pat);
        cout << x << endl;
        for (int i = 0; i<=pat.size(); i++) {
            cout << lps[i];
        }
        cout << endl;
    }
}
