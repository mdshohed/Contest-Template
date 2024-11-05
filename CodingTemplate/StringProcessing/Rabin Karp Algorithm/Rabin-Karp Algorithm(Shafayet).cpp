/*
resource: http://www.shafaetsplanet.com/?p=3028
algorithm: Rabin_karp algorithm
input:
2 
mdshohed
sho
mdshohed
adsf 
output: 
2
-1
*/
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int Hash(string pat, int m, int b ) {
    int h = 0, power = 1;
    for (int i = m-1; i>=0; i--) {
        h = h + (pat[i]*power)%mod;
        h = h%mod;
        power = (power*b)%mod;
    }
    return h;
}

int rk(string txt, string pat) {
    int n = txt.size();
    int m = pat.size();

    int power = 1, b = 347;
    for (int i = 1; i<=m-1; i++) {
        power = (power*b)%mod;

        int hash_txt = Hash(txt, m, b);
        int hash_pattern = Hash(pat, m, b);
        if (hash_pattern==hash_txt) return 0;

        for (int i = m; i<n; i++) {
            hash_txt = (hash_txt - (power*txt[i-m])%mod) % mod;
            hash_txt = (hash_txt+mod) % mod;
            hash_txt = (hash_txt*b) % mod;
            hash_txt =  (hash_txt+txt[i]) % mod;
            if ( hash_pattern==hash_txt) return i-m+1;
        }
    }
    return -1;
}

int main(){

    int t;
    cin >> t;
    while (t--) {
        string txt, pat;
        cin >> txt >> pat;
        int x = rk(txt, pat);
        cout << x << endl;
    }
    return 0;
}
