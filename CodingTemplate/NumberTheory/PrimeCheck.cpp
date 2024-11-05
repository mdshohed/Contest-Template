/*
Time Complexity:
algorithm: Prime check
input:
output:

*/
#include <bits/stdc++.h>
using namespace std;

 //time complexity 0(n^2)
bool isprime(int n) {
    if ( n<2) return false;
    for (int i = 2; i<n; i++) {
        if ( n%i==0 ) return false;
    }
    return true;
}
// Time complexity o(sqrtroot(n))
bool sqrtroot_n(int n ) {
    if ( n<2) return false;
    for (int i = 2; i*i<=n; i++) {
        if ( n%i==0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i<=n; i++) {
        if ( isprime(i)==true) cout << i << " is prime" << endl;
        else cout << i << " is not prime" << endl;
    }
    cout << endl;  
    
    for (int i = 1; i<=n; i++) {
        if ( sqrtroot_n(i)==true) cout << i << " is prime" << endl;
        else cout << i << " is not prime" << endl;
    }
    return 0;
}
