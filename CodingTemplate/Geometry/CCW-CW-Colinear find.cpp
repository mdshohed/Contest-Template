/*
algorithm: Geometry (orientation chack)
input:

output:
counterclockwise/CCW
*/
#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};

int orientation(point p, point q, point r) {
    int val = (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
    if (val==0) return 0;
    return (val>0)?1:2;
}

int main(){
    point p = {0,0}, q = {4,4}, r = {1,2};

    int ans = orientation(p, q, r);
    if ( ans==0 ) cout << "colinear" << endl;
    else if (ans==1) cout << "clockwise/CW" << endl;
    else cout << "counterclockwise/CCW" << endl;

    return 0;
}
