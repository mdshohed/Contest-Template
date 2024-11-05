#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6+7;
int n, cl[mxN], sa[mxN], sa2[mxN], cnt[mxN+1], cl2[mxN];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int m = 26;
    for(int i = 0; i<n; i++) {
        cl[i] = s[i]- 'a'+1;
    }
    for(int l=0; l<n; l*=2) {
        memset(cnt,0,sizeof(cnt));
        for(int i = 0; i<n; i++) {
            ++cnt[cl[i]];
        }
        for(int i=0; i<n; i++){
            cnt[i+1] +=cnt[i];
        }
        for(int i=0; i<n; i++) {
            sa2[--cnt[cl[(i+1)%n]]] = i;
        }
        memset( cnt,0,sizeof(cnt));
        for(int i=0; i<n; i++) {
            ++cnt[cl[i]];
        }
        for(int i=0; i<n; i++) {
            cnt[i+1] += cnt[i];
        }
        for(int i=n-1; ~i; i--) {
            sa[--cnt[cl[sa2[i]]]] = sa2[i];
        }
        m = 0;
        for(int i=0; i<n; i++) {
            if( !m || cl[sa[i]]!=cl[sa[i-1]] || cl[(sa[i]+1)%n]!=cl[(sa[i-1]+1)%n] ) {
                m++;
                cout << m << endl;
            }
            cl2[sa[i]] = m;
        }
        memcpy( cl, cl2, 4*n);
    }
    s+=s;
    cout << s.substr(sa[0], n) << endl;
}
