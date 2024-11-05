/*
source: https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/ 
Algorithm: line segment intersection
input: 

output: 
No
Yes
*/
#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
};

int orientation(point p, point q, point r) {
    int val = (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if (val==0) return 0;
    return (val>0)? 1:2;
}

bool onsegment(point p, point q, point r) {
    if ( q.x <= max(p.x, r.x) && q.x>= max(p.x,r.x) &&
         q.y<=max(p.y, r.y) && p.y>= max(p.y, r.y)) {
            return true;
         }
    return false;
}

int find_intersect(point a1, point b1, point a2, point b2) {
    //cout << a1.x << " " << b1.x << " " << a2.x << " " << b2.x << endl;
    int cross1 = orientation(a1, b1, a2);
    int cross2 = orientation (a1, b1, b2);
    int cross3 = orientation (a2, b2, a1);
    int cross4 = orientation (a2, b2, b1);

    //cout << cross1 << " " << cross2 << " " << cross3 << " " << cross4 << endl;
    if ( cross1!=cross2 && cross3!=cross4 ) return true;

    if ( cross1==0 && onsegment(a1,a2,b1)) return true;
    if ( cross2==0 && onsegment(a1, b2, b1 )) return true;
    if ( cross3==0 && onsegment(a2,a1, b2)) return true;
    if ( cross4==0 && onsegment( a2, b1, b2)) return true;
    return false;
}

int main(){
    point a1 = {1,1}, b1 = {10,1}, a2 = {1,2}, b2 = {10,2};
    if(1==find_intersect(a1,b1,a2,b2)) cout << "Yes" << endl;
    cout << "No" << endl;

    a1 = {10,0}, b1 = {0,10}, a2 = {0,0}, b2 = {10,10};
    if (1==find_intersect(a1, b1, a2, b2)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
