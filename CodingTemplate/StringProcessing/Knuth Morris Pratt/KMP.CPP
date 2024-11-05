#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;
int lps[mx];

void failure_table(string pat, int n) {
    lps[0] = -1;
    int i = 1, j = -1;
    while ( pat[i]) {
        if ( j>=0 && pat[j+1]!=pat[i]) j = lps[j];
        if ( pat[j+1]==pat[i] ) j++;
        lps[i++] = j;
    }
}

int kmp(string txt, string pat) {
    int n = txt.size();
    int m = pat.size();
    failure_table(pat,m);
    for (int i = 0, j = -1; i<n; i++){
        while (j>=0 && txt[i]!=pat[j+1]) j = lps[j];
        if ( txt[i]==pat[j+1]) j++;
        if( j==m-1) return i-j+1;
    }
    return -1;
}

int main() {
    //freopen( "in.txt", "r", stdin );
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n;
        cin >> n;
        string ara[n];
        for (int i =0; i<n; i++) cin >> ara[i];
        for (int i = 0; i<n; i++) {
            int x = kmp(s, ara[i]);
            cout << x << endl;
        }
    }
    return 0;
}
