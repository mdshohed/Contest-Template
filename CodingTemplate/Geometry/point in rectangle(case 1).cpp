/*
algorithm: point in rectangle
input:
output:

*/
#include <bits/stdc++.h>
using namespace std;

struct pt {
    int x, y;
};

int area(pt p, pt q, pt r) {
    return  abs( (p.x*(q.y-r.y)+q.x*(r.y-p.y)+r.x*(p.y-q.y))/2);
}

int main(){
    pt a= {0, 10}, b = {10, 0}, c = {0, -10}, d = {-10, 0};
    pt p = {10, 15};

    double rectangle_are = area(a,b,c) + area(a,c,d);  // at first, we will find  ABCD rectangle area ABCD = ABC+ACD
    double a1 = area(p,a,b);                           // after that will find point are of  area = a1+a2+a3+a4
    double a2 = area(p,b,c);                           // if  point_area== ABCD_area: inside
    double a3 = area(p,c,d);                            // else: outside 
    double a4 = area(p,a,d);
    double point_area = a1 + a2 + a3 + a4;

    if ( point_area==rectangle_are) cout << "inside" << endl;
    else cout << "outside" << endl;
    return 0;
}
