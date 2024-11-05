/*
source: geeksforgeeks
*/
#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
};

int gcd(int a, int b) {
    if ( b==0) return a;
    else return gcd(b,a%b);
}

int boundary_point(point p, point q ) {
    if ( p.x==q.x ) return abs( p.y-q.y)-1;
    if ( p.y==q.y ) return abs( p.x-q.x)-1;
    return gcd(abs( p.x-q.x),abs( p.y-q.y))-1;
}

int getinternalpoint(point p, point q, point r){
    int b_point = boundary_point(p,q)+
                            boundary_point(q,r)+
                            boundary_point(p,r)+3;
    int double_area = abs( p.x*(q.y-r.y) + q.x*(r.y-p.y) + r.x*(p.y-q.y) );
    return ( double_area - b_point+2)/2;
}

int main(){

    point p = {0,0}, q = {0,5}, r = {5,0};
    cout << "triangle internal point: " << endl;
    cout << getinternalpoint(p,q,r) << endl;
    return 0;
}
