#include <bits/stdc++.h>
using namespace std;

int multiple(int k, int ara[], int loop) {
    int temp = 0;
    for (int i = 0; i<loop; i++){
        int rev = ara[i]*k + temp;
        ara[i] = rev%10;
        temp = rev/10;
    }

    while(temp) {
        ara[loop] = temp%10;
        temp/=10;
        loop++;
    }
    return loop;
}

int factorial(int n){
    int ara[1000];
    ara[0] = 1;
    int loop = 1;

    for (int i = 2; i<=n; i++){
        loop = multiple(i, ara, loop);
    }
    cout << "big factorial value:" << endl;
    for(int i = loop-1; i>=0; i--){
        cout << ara[i];
    }
    cout << endl;
}

int main() {

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        factorial(n);
    }
    return 0;
}
