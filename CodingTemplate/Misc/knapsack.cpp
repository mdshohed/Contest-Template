#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+6;

int greedy_method(int price[], int weight[], int n, int w) {

    double unit_price[mx];
    for (int i = 0; i<n; i++) unit_price[i] = price[i]/weight[i];

    for (int i = 0; i<n-1; i++){
        for (int j = 0; j<n-i-1; j++){
            if (unit_price[j]<unit_price[j+1]) {
                swap( price[j],price[j+1]);
                swap(unit_price[j], unit_price[j+1]);
            }
        }
    }

    int profit = 0;
    for (int i = 0; i<n; i++){
        if ( w>=weight[i]) {
            w = w-weight[i];
            profit+=price[i];
        }
        else{
            profit+=w*unit_price[i];
            w = 0;
        }
    }
    cout << endl;
    cout << profit << endl;
}

int main(){

    int n, w;
    cin >> n >> w;
    int price[mx], weight[mx];

    for (int i = 0; i<n; i++) cin >> price[i];
    for (int i = 0; i<n; i++) cin >> weight[i];

    for (int i = 0; i<n; i++){
        cout << price[i] << " ";
    }
    cout << endl;
    greedy_method (price, weight, n, w);

    return 0;
}
