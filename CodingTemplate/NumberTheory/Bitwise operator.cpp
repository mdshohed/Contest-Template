#include <bits/stdc++.h>
using namespace std;

int main() {

    while(1) {
        int n ;
        cin >> n;
        cout << (n <<1) << " " << (n >> 1) << endl; // n right shift means n*2 and left shift means n/2
        cout << (n%32) << " " << (n&31) << endl;    // when n%32 and n/31 use this operation in program-me will be same value
    }
    return 0;
}
