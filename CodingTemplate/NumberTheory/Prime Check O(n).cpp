#include <bits/stdc++.h>
using namespace std;

const int n =  1e+8;
int ara[n+1];
vector<int> prime;

void prime_chack() {
    for (int i = 2; i<=n; i++) {
        if ( ara[i] == 0) {
            ara[i] = i;
            prime.push_back(i);
        }
        for (int j = 0; j<prime.size() && prime[j]<=ara[i] && i*prime[j]<=n; j++) {
            ara[i*prime[j]] = prime[j];
        }
    }
}

int main() {
    prime_chack();

    while(1) {
        int n;
        cin >> n;
        for (int i = 0; i<n; i++) {
            cout << prime[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
