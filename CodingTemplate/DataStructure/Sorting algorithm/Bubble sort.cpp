
#include <bits/stdc++.h>
using namespace std;

int main() {
    //read("input.txt");

    int n;
    cin >> n;
    int ara[100];

    for (int i = 0; i<n; i++) cin >> ara[i];

    for (int i = 0; i<n-1; i++){
        for (int j =0 ; j<n-i-1; j++){
            if ( ara[j] > ara[j+1] ) {
                swap( ara[j],ara[j+1]);
            }
        }
    }

    for (int i = 0; i<n; i++){
        cout << ara[i] << " ";
    }
    cout << endl;
    return 0;
}
