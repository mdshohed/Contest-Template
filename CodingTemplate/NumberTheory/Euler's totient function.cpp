/**
    resource: http://www.progkriya.org/gyan/basic-number-theory.html#section5
              https://www.geeksforgeeks.org/eulers-totient-function/
    algorithm: totient function 
*/

#include <bits/stdc++.h>
using namespace std;

// time complexity O(n)
int pi1(int n ) {

    int cnt = 0;
    for (int i = 1; i<n; i++) {
        if ( __gcd(i,n)==1) {
            cnt++;
        }
    }
    if ( n==1) cnt++;
    return cnt;
}

// Time Complexity: O(nLogn)
int pi2(int n) {
    // prime factor 10: 2,5;
    //  n/2  = 5   where result = 5 ans n = 5
    // if ( n>1) result - return/n  = 5 - 5/5 = 5 - 1 = 4
    // p(10) = 4

    int resut = n;
    for (int i = 2; i*i<=n; i++) {
        if ( n%i==0) {
            while ( n%i==0 ) {
                n/=i;
            }
            resut -= resut/i;
        }
   }
   if ( n>1) resut = resut - resut/n;
   return resut;
}

// Time Complexity O(n log log n)
void pi3() {
    int n = 1e5+7;
    int pi[n];
    for (int i = 0; i<n; i++ ) {
        pi[i] = i;
    }
    for (int j = 2; j<n; j++ ) {
        if (pi[j]==j ) {
            pi[j] = j-1;
            for (int i = 2*j; i<n; i+=j ) {
                pi[i] = ( pi[i]/j ) * ( j-1);
            }
        }
    }
    for (int i = 0; i<100; i++ ) {
        cout << pi[i] << " ";
    }
    cout << endl;
}


int main() {
    freopen( "in.txt", "r", stdin );
    pi3();
    int t;
    cin >> t;
    while ( t-- ) {
        int n;
        cin >> n;
        cout << pi1(n) << " ";
        cout << pi2(n) << endl;
    }
    return 0;
}
