
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    int ara[1000];
    for(int i = 0; i<n; i++){
        cin >> ara[i];
    }

    for (int i = 1; i<n; i++){
        int x = ara[i];
        int j = i-1;
        while ( j >=0 && ara[j]>x ){
            ara[j+1] = ara[j];
            j = j-1;
        }
        ara[j+1] = x;
    }
    
    for(int i = 0; i<n; i++){
        cout << ara[i] << " ";
    }
    cout << endl;
    return 0;
}
