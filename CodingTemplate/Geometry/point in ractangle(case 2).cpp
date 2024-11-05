/*
algorithm: point in rectangle 
input: 
output:

*/
#include <bits/stdc++.h>
using namespace std;

#define db(x) cout << #x << " " << x << endl;
struct point {
    int x, y;
};
// the function return whether point p inside or outside of rectangle 
bool find_inside(point a, point b, point p) {
    if ( p.x>a.x && p.x<b.x && p.y > a.y && p.y<b.y) return true;
    else return false;
}

int main(){
    point a = {1,2}, b = {8,10};    //given rectangle point bottom-left and upper-right
                                    // find that if p inside of rectangle or not 
    point p = {5,6};
    int ans =  find_inside(a,b,p);
    if( ans) cout << "yes" << endl;
    else cout << "No" << endl;
    return 0;
}
