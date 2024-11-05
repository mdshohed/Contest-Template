/**
input:
3 3
2 10
1 4
2 20
output:
Item - 3: 2 = 20
Item - 1: 1 = 5
profit: 25

*/
#include <bits/stdc++.h>
using namespace std;

struct item {
    double x , w, p, u;
};

bool cmp(item a, item b ) {
    return a.u > b.u;
}

int main() {
    freopen( "in.txt", "r", stdin );

    int w, n;
    cin >> w >> n;

    item ara[100];
    for (int i = 0; i<n; i++) {
        cin >> ara[i].w >> ara[i].p;
        ara[i].x = i+1;
        ara[i].u = ara[i].p/ara[i].w;
    }

    sort( ara, ara+n, cmp);

    int maximum = 0;

    for (int i = 0; i<n; i++) {
        if ( w>ara[i].w ){
            maximum +=ara[i].p;
            w-=ara[i].w;
            cout << "Item - " << ara[i].x << ": " << ara[i].w << " = " << ara[i].p << endl;
        }
        else {
            maximum += w*ara[i].u;
            cout << "Item - " << ara[i].x << ": " << w << " = " << w*ara[i].p << endl;
            w = 0;
            break;
        }
    }
    cout << "Profit: " << maximum << endl;
    return 0;
}
