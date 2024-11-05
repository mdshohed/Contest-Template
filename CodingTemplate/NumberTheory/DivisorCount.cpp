/*
Time complexity: root(n)
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void divisor(int n){
    for (int i = 1; i*i<=n; i++) {
        if ( i*i==n ) v.push_back(i);
        else if ( n%i==0) {
            v.push_back(i);
            v.push_back(n/i);
        }
    }
}

int main() {
    int n;
    cin >> n;
    divisor(n);
    sort(v.begin(),v.end());
    for (int i = 0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
