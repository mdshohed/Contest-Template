#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define all(x) begin(x),end(x)

const int maxn = 1e6 + 7; 

int main() {
#ifdef LOCAL
    ios_base::sync_with_stdio(false),cin.tie(nullptr); 
#else
    freopen( "in.txt", "r", stdin);
    //freopen( "out.txt","w", stdout);
#endif
    int tc, cases = 0; 
    cin >> tc; 
    while (tc--) {
        char s[maxn], t[maxn];
        scanf("%s", &s);
        strcpy(t, s); 
        reverse(t, t+strlen(t));
        int m = strlen(t);
        vector<int> lps(m); 
        int i = 1, j = 0; 
        while(i<m) {
            if(t[i]==t[j]) {
                lps[i++] = ++j;
            }
            else {
                if( j!=0) j = lps[j-1]; 
                else i++; 
            }
        }
        i = 0, j = 0;
        while( i<m ) {
            if( s[i]==t[j]) {
                i++, j++;

            }
            else{
                if( j!=0 ) j = lps[j-1]; 
                else i++; 
            }
        }
        int match = m - j;
        cout << m << " " << j << endl; 
        cout << "Case " << ++cases << ": " << m + match << endl;
        cout << s; 
        for(int i = 1; i<=match; i++) cout << t[i];
        cout << endl; 
    }
    return 0;
}

// 4
// bababababa
// pqrs
// madamimadam
// anncbaaababaaa
