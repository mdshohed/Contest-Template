/*
    Reference:  https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/tutorial/
*/
#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;
int p[mx*2];

string convertnewstring( string s ) {
    string ans = "@";
    for (int i = 0; i<s.size(); i++ ) {
        ans += "#" + s.substr( i, 1 );
    }
    ans += "#$";
    return ans;
}

string palindrom( string s) {
    string ans = convertnewstring(s);
    int r = 0, c = 0;

    for (int i = 1; i<ans.size()-1; i++ ) {
        int imin = c - (i - c);
        if ( r>i) {
            p[i] = min( r - i, p[imin]);
        }
        while ( ans[i + 1 + p[i]] == ans[i - 1 - p[i]]) {
            p[i]++;
        }
        if ( i+p[i] > r ) {
            c = i;
            r =  i + p[i];
        }
    }
    int mx = 0;
    int center = 0;
    for (int i = 1; i<ans.size(); i++ ) {
        if ( p[i] > mx ) {
            mx = p[i];
            center = i;
        }
    }
    cout << mx << endl;
    return s.substr( (center - 1- mx )/2, mx);
}

int main() {
    string s ;
    cin >> s;
    cout << palindrom(s) << endl;
}

/*
Test Case: 

Input: 
mdshohed

output: 
3
hoh
*/
