#include <bits/stdc++.h>
using namespace std;

int main() {

    string a;
    cin >> a;
    char s[a.size()];
    int n, k;
    cin >> n >> k;

    for (int i = 0; i<n; i++) {
        int x = ( i+k)%n;
        s[x] = a[i];
    }
    s[n] = '\0';
    cout << s << endl;
}
