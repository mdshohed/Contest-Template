/*
source: 
algorithm: find a point inside or outside of circle
input: 
0 1
1 1
2
output: 
inside
*/
#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};

int isinside(point circle_p, point p, int redious ) {
    if ( (circle_p.x-p.x)*(circle_p.x-p.x) + (circle_p.y-p.y)*(circle_p.y-p.y)<=redious*redious) {
        return true;
    }
    else return false;
}

int main() {
    point circle_point = {0,1}, p = {1,1};
    int circle_redious = 2;

    if ( isinside(circle_point,p,circle_redious)) cout << "inside" << endl;
    else cout << "outside" << endl;
    return 0;
}
