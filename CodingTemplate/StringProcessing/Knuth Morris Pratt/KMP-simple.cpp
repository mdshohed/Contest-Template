/*
   Reference: https://github.com/mission-peace/interview/blob/master/C%2B%2B/String%20Algorithms/KMP.cpp
   Time Complexity: O(n+m)
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function( string s) {
    int n = s.size();
    vector<int> f(n);
    f[0] = 0;
    for ( int i = 1; i<n; i++) {
        int j = f[i-1];
        while ( j>0 && s[i]!=s[j] ){
            j = f[j-1];
        }
        if ( s[i]==s[j] ) {
             ++j;
        }
        f[i] = j;
    }
    return f;
}

void kmp( string s, string t) {
    int n = s.size();
    int m = t.size();

    vector<int> prefix = prefix_function(t);

    int ans = 0;
    for (int i = 0, j =0; i<n; i++ ) {
        while ( j>0 && s[i]!=t[j]) {
            j = prefix[j-1];
        }
        if ( s[i]==t[j] ) {
            j++;
        }
        if ( j==m ) {
            ans++;
            cout << i - m + 1 << " "; 
            j = prefix[j-1];
        }
    }
    cout << endl;  
    cout << ans << endl;
}

int main() {
    string s,t;
    cin >> s >> t;
    kmp( s, t);
}
