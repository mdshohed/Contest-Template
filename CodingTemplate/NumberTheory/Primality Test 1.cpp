/*
Time complexity: O(√n)
algorithm: Primality Test 1
input:
output:
*/
#include <bits/stdc++.h>
using namespace std;

bool isprime(int n) {
    if ( n<2) return false;
    if ( n==2 ) return true;
    if ( n%2==0) return false;
    for (int i = 3; i*i<=n; i+=2) {
        if ( n%i==0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i<n; i++) {
        if ( isprime(i)==true) {
            cout << i << " is prime " << endl;
        }
        else  cout << i << " is not prime " << endl;
    }
    return 0;
}
