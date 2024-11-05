/*
Time Complexity: O(Nlog(logN))
algorithm: sieve
input:
output:
*/
#include <bits/stdc++.h>
using namespace std;

const int mx = 1e7+7;
bool prime[mx];
vector<int> v;

/*void sieve(){
    //v.push_back(2);
    for (int i = 3; i*i<=mx; i+=2) {
        if (prime[i]==false) {
            for (int j = i*i; j<=mx; j+=i+i) {
                prime[j] = true;
            }
        }
    }
    cout << 2 << " ";
    for (int i = 3; i<=1000; i+=2) {
        if ( prime[i]==false){
            cout << i << " "; 
            v.push_back(i); 
        }
    }
    cout << endl;
}*/

void sieve() {
    memset(prime,true,sizeof(prime));
    for (int i = 0; i<=mx; i+=2) prime[i] = false;
    prime[0] = prime[1] = false;
    prime[2] = true;
    for (int i = 3; i*i<=mx; i+=2) {
        if (prime[i]) {
            for (int j = i*i; j<=mx; j+=i+i) {
                prime[j] = false;
            }
        }
    }
    v.push_back(2);
    for (int i = 3; i<=mx; i+=2) {
        if ( prime[i]) v.push_back(i);
    }
}

int main (){
    //freopen( "in.txt", "r", stdin );
    sieve()
    int n = 100;
    //cin >> n;
    // print prime Number form 1 to 100;
    for (int i = 0; i<=n; i++) {
        if ( prime[i]) {
            cout << i << " is prime" << endl;
        }
        else cout << i << " is not prime" << endl;
    }
    // prime 100 prime Number
    for (int i = 0; i<n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;

}
