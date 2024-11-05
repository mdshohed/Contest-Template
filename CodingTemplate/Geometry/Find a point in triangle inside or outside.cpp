/*
source: youtube.com/TECH DOSE
algorithm: check a point inside triangle  or outside
input:
0 0
20 0
10 30
10 15

output:
inside
*/
#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};

double area(point a, point b, point c) {
    return abs(a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y))/2;   // area = 1/2*[ x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)]
                                                            // => abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2  // abs using for positive value
}

int main() {
    //freopen( "in.txt", "r", stdin );
    point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    point p;
    cin >> p.x >> p.y;
    double area1 = area( a,b,p);
    double area2 = area(a,c,p);
    double area3 = area(b,c,p);
    
    //cout << area1 << " " << area2 << " " << area3 << endl;
    double point_area = area1 + area2 + area3;
    cout << point_area << endl;

    double triangle_area = area(a,b,c);
    cout << triangle_area << endl;

    if ( point_area==triangle_area ) cout << "inside" << endl;
    else cout << "outside" << endl;
    return 0;
}
