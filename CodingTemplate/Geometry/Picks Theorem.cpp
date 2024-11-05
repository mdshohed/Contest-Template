/*
source: 1: https://reponroy.wordpress.com/2015/09/06/picks-theorem/
        2: https://codeforces.com/blog/entry/65888
algorithm: pick's theory
input: 
1
4
0 0
4 0
0 4
4 4
output: 
16 12
*/
#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
    point(){}
    point (int x, int y):x(x),y(y){}
    point operator - (const point &a) {
        return {x - a.x, y - a.y};
    }

}ara[100];

int cross(point p, point q) {
    return  p.x*q.y  - p.y*q.x;
}

int gcd(int a, int b) {
    if (b==0) return a;
    else return (b,a%b);
}

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i<n; i++) {
            int a,b;
            cin >> a >> b;
            ara[i] = {a,b};
        }
        int area = 0;
        for (int i = 0; i<n; i++) {
            area += cross( ara[i], ara[(i+1)%n] );
        }
        area = abs( area);   // area = area/2 then we get actual result of area point
        cout << "area of polygon: " <<  area/2 << endl;

        int ats = 0;
        for (int i = 0; i<n; i++) {
            int dx =  (ara[i].x - ara[(i+1)%n].x);
            int dy = (ara[i].y - ara[(i+1)%n].y);
            ats  += abs(__gcd(dx, dy))-1;
        }
        cout << "boudary point: " << ats << endl;

/*
        int boundary = 0;
        for (int i = 0; i<n; i++) {
            point dx = ara[(i+1)%n] - ara[i];
            int g = gcd(dx.x,dx.y);
            boundary += abs(g);
        }
        int ans = ( area+2 - boundary)/2;
        cout << ans << endl;
*/
    }
    return 0;
}
