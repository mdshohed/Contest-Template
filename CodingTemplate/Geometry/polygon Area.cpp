/*
source: youtube.com/mycodeschool
algorithm: polygon area
input:
4
0 0
0 4
4 0
4 4
output:
16

*/
#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
}ara[1000];

// find two vector cross product
double cross_product(point p, point q) {
    return p.x*q.y - p.y*q.x;
}

// find total area of polygon
int area_polygon (point ara[], int n) {
    int sum = 0;
    for (int i = 0; i<n; i++) {
        sum += cross_product(ara[i], ara[(i+1)%n]);
    }
    return abs(sum)/ 2;
}

int main(){
    //freopen( "in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        ara[i] = {x,y};
    }
    cout << area_polygon( ara, n ) << endl;
    return 0;
}
