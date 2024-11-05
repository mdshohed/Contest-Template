#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// recurtion formula..
int total_sum (int cost[], int i, int j ) {
    int s = 0;
    for (int x = i; x<j; x++){
        s += cost[x];
    }
    return s;
}

int frequency(int cost[], int i, int j ) {
    if ( j<i ) return 0;
    if ( i==j ) return cost[i];

    int sum = total_sum(cost, i, j);
    int min_val = INT_MAX;

    for (int x=i; x<j; x++){
        int new_cost = frequency( cost, i, x-1 ) + frequency( cost, x+1, j);
        if( new_cost < min_val) min_val = new_cost;
    }
    return sum + min_val;
}

int costfrequency (int ara[], int cost[], int n) {
    return frequency(cost , 0, n-1);
}




int main() {
    int n;
    int value[] = {10, 12, 20};
    int cost[] = {58, 38, 8 };
    cin >> n;
    cout << costfrequency( value, cost, n) << endl;
    return 0;
}
