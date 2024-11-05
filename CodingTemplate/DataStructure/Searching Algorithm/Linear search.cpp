#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ara[1000];
    for (inti i = 0; i<n; i++) cin >> ara[i];

    int search, position = -1;
    for (int i = 0; i<n; i++){
        if ( ara[i] == search) {
            position = i;
            break;
        }
    }
    if ( position ==-1) {
        cout << "the value found array position: " << position << endl;
    }
    else {
        cout << "the value not found in array" << endl;
    }
    return 0;
}
