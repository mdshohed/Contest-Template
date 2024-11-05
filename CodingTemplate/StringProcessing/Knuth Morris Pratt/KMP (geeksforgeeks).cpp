/*
Algorithm: kpm (knuth morris pratt) 
input: 
mdshohed 
sho
output: 
found pattern at index 2

*/
#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;
int lps[mx];

void computelpsara(string pat) {
    int m = 0, i = 0;
    lps[0] = 0;             // this function compute lps value from pattern string
    for (int i = 1; i<pat.size(); i++) {
        if ( pat[i]==pat[m] ) {
            lps[i] = ++m;
        }
        else {
            if ( m!=0 ) {
                m = lps[m-1];
                i--;
            }
            else {
                lps[i] = 0;
            }
        }
    }
}

int kmp(string txt, string pat) {
    int i = 0, j = 0;        // according to lps function will find txt and pattern matching 
    bool ok = 0;
    while (i<txt.size()) {
        if ( txt[i]==pat[j]) {
            i++, j++;
        }
        if ( j==pat.size()) {
            cout << "found pattern at index " << i-j << endl;
            ok = 1;
            j = lps[j-1];
        }
        else if ( i<txt.size() && txt[i]!=pat[j] ) {
            if (j!= 0) {
                j = lps[j-1];
            }
            else i++;
        }
    }
    if (!ok) cout << "NOt found" << endl;
}

int main() {
    string txt, pat;
    cin >> txt >> pat;

    computelpsara(pat);
    kmp(txt, pat);

    return 0;
}
