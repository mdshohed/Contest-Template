/*
Time complexity: 
algorithm: Prime factor
input:
output:
*/
#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;
bool prime[mx];
vector<int> v;
vector<int> factor;

void sieve(){
    v.push_back(2);
    for(int i = 3; i*i<=mx; i+=2) {
        if (prime[i]==false) {
            for (int j = i*i; j<=mx; j+=i+i ) {
                prime[j] = true;
            }
        }
    }
    for (int i = 3; i<=mx; i+=2) {
        if(prime[i]==false) v.push_back(i);
    }
}

void primefactor(int n) {
    for (int i = 0; v[i]*v[i]<=n; i++) {
        if ( n%v[i]==0) {
            while ( n%v[i]==0) {
                n/=v[i];
                factor.push_back(v[i]);
            }
        }
    }
    if ( n!=1 ) factor.push_back(n);
}

int main () {
    sieve();
    int t;
    t = 1; 
    while ( t--) {
        int n = 25;  
        primefactor(n);
        for (int i = 0; i<factor.size(); i++) {
            cout << factor[i] << " ";
        }
        cout << endl;
        factor.clear();
    }

    int n = 100; 
    map<int,int> mp;  
    for(int i = 2; i<=sqrt(n); i++){
        while( n%i == 0){
            mp[i]++;
            n/=i; 
        }
    }
    if(n>1) mp[n]++; 
    return 0;
}
